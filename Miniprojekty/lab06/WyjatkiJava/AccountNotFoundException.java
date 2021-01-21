class AccountNotFoundException extends Exception {
    static final long serialVersionUID = 1L;
    private int number;
    private Customer customer;

    AccountNotFoundException(){}
    AccountNotFoundException(int n) {
        super("Account not found!");
        this.number = n;
    }

    AccountNotFoundException(Customer cust){
        super("Account not found!");
        this.customer = cust;
    }

    int getNumber() {
        return number;
    }

    Customer getCustomer() {
        return customer;
    }
}
