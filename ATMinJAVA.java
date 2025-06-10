import java.util.*;

class Transaction {
    String type;
    double amount;
    Date timestamp;

    Transaction(String type, double amount) {
        this.type = type;
        this.amount = amount;
        this.timestamp = new Date();
    }

    public String toString() {
        if (type.equals("Deposit")) {
            return " + " + type + " of Rupees " + amount + " on " + timestamp;
        } else {
            return " - " + type + " of Rupees " + amount + " on " + timestamp;
        }
    }
}

class Account {
    String name;
    String AadharNumber;
    String PANNumber;
    long phoneNumber;
    int accountNumber;
    double balance;
    List<Transaction> transactions;

    Account(String name, int accountNumber, String AadharNumber, long phoneNumber) {
        this.name = name;
        this.accountNumber = accountNumber;
        this.balance = 0.0;
        this.transactions = new ArrayList<>();
        this.AadharNumber = AadharNumber;
        this.phoneNumber = phoneNumber;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            System.out.println("> Invalid deposit amount.");
            return;
        }
        balance += amount;
        transactions.add(new Transaction("Deposit", amount));
        System.out.println("> Rupees " + amount + " deposited successfully.");
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            System.out.println("> Invalid withdrawal amount.");
        } else if (amount > balance) {
            System.out.println("> Insufficient balance.");
        } else {
            balance -= amount;
            transactions.add(new Transaction("Withdraw", amount));
            System.out.println("> Rupees " + amount + " withdrawn successfully.");
        }
    }

    void checkBalance() {
        System.out.println("> Current Balance: Rupees " + balance);
    }

    void loan(double amount) {
        if (name.contains("Vijay") || name.contains("Malya")) {
            System.out.println("> Loan request denied for Vijay Malya.");

        } else {
            if (amount > 500000) {
                System.out.println("> Loan amount exceeds the limit of Rupees 500000.");
            } else {
                if (amount <= 0) {
                    System.out.println("> Invalid loan amount.");
                } else {
                    balance += amount;
                    transactions.add(new Transaction("Loan", amount));
                    System.out.println("> Loan of Rupees " + amount + " approved and added to your balance.");
                }
            }
        }
    }

    void showTransactionHistory() {
        if (transactions.isEmpty()) {
            System.out.println("> No transactions yet.");
        } else {
            System.out.println("> Transaction History:");
            for (Transaction t : transactions) {
                System.out.println(t);
            }
        }
    }
}

public class ATMinJAVA {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random rand = new Random();

        System.out.print("> Enter your name: ");
        String name = sc.nextLine();
        System.out.print("> Enter your Aadhar Number : ");
        String AadharNumber = sc.nextLine();
        if (AadharNumber.length() != 12) {
            System.out.println("> Invalid Aadhar Number. It should be 12 digits long.");
            System.out.print("> Please re-enter your Aadhar Number: ");
            AadharNumber = sc.nextLine();

        }

        System.out.print("> Enter your Mobile Number : ");
        long Mobileno = sc.nextLong();
        int accNumber = 100000000 + rand.nextInt(900000);

        Account acc = new Account(name, accNumber, AadharNumber, Mobileno);

        System.out.println("> Account created successfully!");
        System.out.println("> Name: " + acc.name);
        System.out.println("> Aadhar Number: " + acc.AadharNumber);
        System.out.println("> Phone Number: " + acc.phoneNumber);
        System.out.println("> Account Number: " + acc.accountNumber);
        System.out.println("> Initial Balance: Rupees " + acc.balance);

        int choice;
        do {
            System.out.println("\n===== ATM Menu =====");
            System.out.println("1. Deposit");
            System.out.println("2. Withdraw");
            System.out.println("3. Check Balance");
            System.out.println("4. View Transaction History");
            System.out.println("5. Apply for Loan ");
            System.out.println("6. Exit");
            System.out.print("> Choose an option: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter amount to deposit: Rupees ");
                    double dep = sc.nextDouble();
                    acc.deposit(dep);
                    try {
                        Thread.sleep(2000);
                    } catch (InterruptedException e) {
                        
                        e.printStackTrace();
                    }
                    break;
                case 2:
                    System.out.print("Enter amount to withdraw: Rupees ");
                    double wd = sc.nextDouble();
                    acc.withdraw(wd);
                      try {
                        Thread.sleep(2000);
                    } catch (InterruptedException e) {
                      
                        e.printStackTrace();
                    }
                    break;
                case 3:
                    acc.checkBalance();
                      try {
                        Thread.sleep(2000);
                    } catch (InterruptedException e) {
                       
                        e.printStackTrace();
                    }
                    break;
                case 4:
                    acc.showTransactionHistory();
                      try {
                        Thread.sleep(2000);
                    } catch (InterruptedException e) {                 
                    }
                    break;
                case 5:
                    System.out.print("Enter loan Amount : ");
                    double loan = sc.nextDouble();
                    acc.loan(loan);
                      try {
                        Thread.sleep(2000);
                    } catch (InterruptedException e) {
                      
                    }
                    break;
                case 6:
                    System.out.println("> Thank you for using the ATM. Goodbye!");
                    break;
                default:
                    System.out.println("> Invalid option. Try again.");
                      try {
                        Thread.sleep(200);
                    } catch (InterruptedException e) {
                    }
            }
        } while (choice != 6);

        sc.close();
    }
}