class AccountLoginFailedException extends Exception {
    static final long serialVersionUID = 1L;
    private int password;
    private String login;
    private int accountNumber;
    private Customer owner;
    private double balance;

    AccountLoginFailedException() {
        super("Login error");
    }
    AccountLoginFailedException(String errorMsg, String s, int passwd) {
        super(errorMsg);
        login = s;
        password = passwd;
    }
    AccountLoginFailedException(String errorMsg, String s, int passwd, int an, Customer c, double b) {
        super(errorMsg);
        login = s;
        password = passwd;
        accountNumber = an;
        owner = c;
        balance = b;
    }

    int getPassword ( ) {
        return password;
    }
    String getLogin ( ) {
        return login;
    }
}
