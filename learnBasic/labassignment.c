/*
 Bank Account Management System (C)
 - Account: account number, name, balance
 - Operations: create, view, deposit, withdraw
 - Persistence: load/save accounts from "accounts.csv"
 - Per-account transaction log: "acc_<accno>_trans.txt"
 - Save single account to "account_<accno>.txt"
 - Profit projection (simple & monthly-compound interest)
 
 Save this file as labassignment.c and compile:
    gcc -std=c11 -o bank labassignment.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ACCOUNTS 1000
#define NAME_LEN 100
#define ACC_FILE "accounts.csv"

typedef struct {
     int acc_no;
     char name[NAME_LEN];
     double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int acc_count = 0;

/* Utility: current timestamp string */
void current_time_str(char *buf, size_t n) {
     time_t t = time(NULL);
     struct tm *tm = localtime(&t);
     strftime(buf, n, "%Y-%m-%d %H:%M:%S", tm);
}

/* Load accounts from CSV file */
void load_accounts(const char *filename) {
     FILE *f = fopen(filename, "r");
     if (!f) return; // no file yet
     char line[256];
     while (fgets(line, sizeof(line), f) && acc_count < MAX_ACCOUNTS) {
          // Expect: acc_no,name,balance
          int acc;
          char name[NAME_LEN];
          double bal;
          // remove newline
          char *p = strchr(line, '\n'); if (p) *p = '\0';
          // simple parsing (names should not contain commas)
          if (sscanf(line, "%d,%99[^,],%lf", &acc, name, &bal) == 3) {
                accounts[acc_count].acc_no = acc;
                strncpy(accounts[acc_count].name, name, NAME_LEN-1);
                accounts[acc_count].name[NAME_LEN-1] = '\0';
                accounts[acc_count].balance = bal;
                acc_count++;
          }
     }
     fclose(f);
}

/* Save all accounts to CSV */
void save_accounts(const char *filename) {
     FILE *f = fopen(filename, "w");
     if (!f) {
          printf("Error saving accounts to %s\n", filename);
          return;
     }
     for (int i = 0; i < acc_count; ++i) {
          fprintf(f, "%d,%s,%.2f\n", accounts[i].acc_no, accounts[i].name, accounts[i].balance);
     }
     fclose(f);
}

/* Find account index by acc_no, return -1 if not found */
int find_account_index(int acc_no) {
     for (int i = 0; i < acc_count; ++i)
          if (accounts[i].acc_no == acc_no) return i;
     return -1;
}

/* Append transaction log */
void append_transaction(int acc_no, const char *type, double amount, double newbal) {
     char fname[64];
     snprintf(fname, sizeof(fname), "acc_%d_trans.txt", acc_no);
     FILE *f = fopen(fname, "a");
     if (!f) return;
     char ts[64];
     current_time_str(ts, sizeof(ts));
     fprintf(f, "%s,%s,%.2f,%.2f\n", ts, type, amount, newbal);
     fclose(f);
}

/* Create new account */
void create_account() {
     if (acc_count >= MAX_ACCOUNTS) {
          printf("Account limit reached.\n");
          return;
     }
     int acc_no;
     char name[NAME_LEN];
     double init;
     printf("Enter new account number: ");
     if (scanf("%d", &acc_no) != 1) { while (getchar()!='\n'); return; }
     if (find_account_index(acc_no) != -1) {
          printf("Account number already exists.\n");
          return;
     }
     printf("Enter account holder name: ");
     while (getchar()!='\n'); // flush newline
     if (!fgets(name, sizeof(name), stdin)) return;
     char *p = strchr(name, '\n'); if (p) *p = '\0';
     printf("Initial deposit: ");
     if (scanf("%lf", &init) != 1) { while (getchar()!='\n'); return; }
     accounts[acc_count].acc_no = acc_no;
     strncpy(accounts[acc_count].name, name, NAME_LEN-1);
     accounts[acc_count].name[NAME_LEN-1] = '\0';
     accounts[acc_count].balance = init;
     acc_count++;
     append_transaction(acc_no, "CREATE", init, init);
     printf("Account created.\n");
}

/* View account details and optionally transactions */
void view_account() {
     int acc_no;
     printf("Enter account number: ");
     if (scanf("%d", &acc_no) != 1) { while (getchar()!='\n'); return; }
     int idx = find_account_index(acc_no);
     if (idx == -1) {
          printf("Account not found.\n");
          return;
     }
     printf("Account: %d\nName: %s\nBalance: %.2f\n", accounts[idx].acc_no, accounts[idx].name, accounts[idx].balance);
     printf("Show transactions? (y/n): ");
     char c;
     while (getchar()!='\n'); // flush
     c = getchar();
     if (c == 'y' || c == 'Y') {
          char fname[64];
          snprintf(fname, sizeof(fname), "acc_%d_trans.txt", acc_no);
          FILE *f = fopen(fname, "r");
          if (!f) {
                printf("No transactions found.\n");
                return;
          }
          char line[256];
          printf("Timestamp,Type,Amount,BalanceAfter\n");
          while (fgets(line, sizeof(line), f)) {
                printf("%s", line);
          }
          fclose(f);
     }
}

/* Deposit */
void deposit() {
     int acc_no;
     double amt;
     printf("Account number: ");
     if (scanf("%d", &acc_no) != 1) { while (getchar()!='\n'); return; }
     int idx = find_account_index(acc_no);
     if (idx == -1) { printf("Account not found.\n"); return; }
     printf("Amount to deposit: ");
     if (scanf("%lf", &amt) != 1 || amt <= 0) { printf("Invalid amount.\n"); while (getchar()!='\n'); return; }
     accounts[idx].balance += amt;
     append_transaction(acc_no, "DEPOSIT", amt, accounts[idx].balance);
     printf("Deposit successful. New balance: %.2f\n", accounts[idx].balance);
}

/* Withdraw */
void withdraw() {
     int acc_no;
     double amt;
     printf("Account number: ");
     if (scanf("%d", &acc_no) != 1) { while (getchar()!='\n'); return; }
     int idx = find_account_index(acc_no);
     if (idx == -1) { printf("Account not found.\n"); return; }
     printf("Amount to withdraw: ");
     if (scanf("%lf", &amt) != 1 || amt <= 0) { printf("Invalid amount.\n"); while (getchar()!='\n'); return; }
     if (accounts[idx].balance < amt) { printf("Insufficient balance.\n"); return; }
     accounts[idx].balance -= amt;
     append_transaction(acc_no, "WITHDRAW", amt, accounts[idx].balance);
     printf("Withdrawal successful. New balance: %.2f\n", accounts[idx].balance);
}

/* Save single account to file account_<accno>.txt */
void save_single_account() {
     int acc_no;
     printf("Account number to save: ");
     if (scanf("%d", &acc_no) != 1) { while (getchar()!='\n'); return; }
     int idx = find_account_index(acc_no);
     if (idx == -1) { printf("Account not found.\n"); return; }
     char fname[64];
     snprintf(fname, sizeof(fname), "account_%d.txt", acc_no);
     FILE *f = fopen(fname, "w");
     if (!f) { printf("Could not write file.\n"); return; }
     fprintf(f, "Account: %d\nName: %s\nBalance: %.2f\n", accounts[idx].acc_no, accounts[idx].name, accounts[idx].balance);
     fclose(f);
     printf("Saved account to %s\n", fname);
}

/* Profit projection: simple interest and monthly compound */
void calculate_profit() {
     int acc_no;
     printf("Account number: ");
     if (scanf("%d", &acc_no) != 1) { while (getchar()!='\n'); return; }
     int idx = find_account_index(acc_no);
     if (idx == -1) { printf("Account not found.\n"); return; }
     double rate, years;
     printf("Annual interest rate (percent): ");
     if (scanf("%lf", &rate) != 1) { while (getchar()!='\n'); return; }
     printf("Time period (years, e.g., 1.5): ");
     if (scanf("%lf", &years) != 1) { while (getchar()!='\n'); return; }
     double P = accounts[idx].balance;
     double simple_profit = P * (rate/100.0) * years;
     double simple_final = P + simple_profit;
     // monthly compounding
     double n = 12.0;
     double compound_final = P * pow(1.0 + (rate/100.0)/n, n*years);
     double compound_profit = compound_final - P;
     printf("Current balance: %.2f\n", P);
     printf("Simple interest profit: %.2f    Final balance: %.2f\n", simple_profit, simple_final);
     printf("Monthly-compounded profit: %.2f    Final balance: %.2f\n", compound_profit, compound_final);
}

/* Print menu */
void menu() {
     printf("\n--- Bank Account Management ---\n");
     printf("1. Create account\n");
     printf("2. View account & transactions\n");
     printf("3. Deposit\n");
     printf("4. Withdraw\n");
     printf("5. Save all accounts to file\n");
     printf("6. Save single account to file\n");
     printf("7. Calculate profit / projection\n");
     printf("8. Exit\n");
     printf("Choose an option: ");
}

int main(void) {
     load_accounts(ACC_FILE);
     int choice;
     while (1) {
          menu();
          if (scanf("%d", &choice) != 1) { while (getchar()!='\n'); continue; }
          switch (choice) {
                case 1: create_account(); break;
                case 2: view_account(); break;
                case 3: deposit(); break;
                case 4: withdraw(); break;
                case 5: save_accounts(ACC_FILE); printf("All accounts saved to %s\n", ACC_FILE); break;
                case 6: save_single_account(); break;
                case 7: calculate_profit(); break;
                case 8: save_accounts(ACC_FILE); printf("Exiting. Accounts saved.\n"); return 0;
                default: printf("Invalid option.\n"); break;
          }
     }
     return 0;
}