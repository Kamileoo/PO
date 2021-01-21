class CustomerNotFoundException extends Exception {
    static final long serialVersionUID = 1L;
    private String name;

    CustomerNotFoundException(){}
    CustomerNotFoundException(String n){
        super("Customer not found!");
        this.name = n;
    }

    String getName() {
        return name;
    }
}
