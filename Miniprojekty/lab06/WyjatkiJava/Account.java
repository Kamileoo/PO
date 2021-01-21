public class Account {
    private int accountNumber;
    private Customer owner;
    private double balance;
    private int password;
    private String login;
    public Account(){}
    public Account(int n, Customer c, int p, String l) {
        this.accountNumber = n;
        this.owner = c;
        this.password = p;
        this.login = l;
    }
    public Account(int n, Customer c, double b, int p, String l) {
        this.accountNumber = n;
        this.owner = c;
        this.balance = b;
        this.password = p;
        this.login = l;
    }
    public void login (String l, int passwd) throws AccountLoginFailedException {
            if(this.login != l) {
                throw new AccountLoginFailedException("There in no suach a login in a database!", l, passwd);
            }
            else if (this.password != passwd) {
                throw new AccountLoginFailedException("Wrong password!", l, passwd);
            }
            else {
                System.out.println( "Logged!" );
            }
    }
    public Customer getCustomer() {
        return owner;
    }
    public int getNumber() {
        return accountNumber;
    }
    public double getBalance() {
        return balance;
    }
    public double withdraw (double amount) {
        this.balance -= amount;
        return balance;
    }
    }
    