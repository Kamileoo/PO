class AddNewCustomerFailedException extends Exception {
    static final long serialVersionUID = 1L;
    private int PESEL;
    private String name;
    private String firstName;

    AddNewCustomerFailedException() {
        super("New customer error");
    }
    AddNewCustomerFailedException(String n, String fn, int p) {
        super("New customer error");
        name = n;
        firstName = fn;
        PESEL = p;
    }

    int getPESEL ( ) {
        return PESEL;
    }
    String getName ( ) {
        return name;
    }

    String getFirstName ( ) {
        return firstName;
    }
}