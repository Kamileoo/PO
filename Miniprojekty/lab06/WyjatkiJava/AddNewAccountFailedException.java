class AddNewAccountFailedException extends Exception {
    static final long serialVersionUID = 1L;
    private int accountNumber;
    private Customer owner;
    private double balance;
    private int password;
    private String login;

    AddNewAccountFailedException() {
        super("New account error");
    }
    AddNewAccountFailedException(int an, Customer c, double b, int p, String l) {
        super("New account error");
        accountNumber = an;
        owner = c;
        balance = b;
        password = p;
        login = l;
    }

    int getAccountNumber ( ) {
        return accountNumber;
    }

    Customer getCustomer ( ) {
        return owner;
    }

    double getBalance() {
        return balance;
    }

    int getPassword() {
        return password;
    }

    String getLogin() {
        return login;
    }
}