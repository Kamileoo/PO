

public class Customer {
    private String name;
    private String firstName;
    private int PESEL;

    public Customer(){}
    public Customer(String s){
        this.name = s;
    }
    public Customer(String s, String fn, int p){
        this.name = s;
        this.firstName = fn;
        this.PESEL = p;
    }

    public String getName(){
        return name;
    }

    public String getFirstName(){
        return firstName;
    }
    
    public int getPESEL(){
        return PESEL;
    }

    @Override
    public boolean equals(Object c){
        if (! (c instanceof Customer)){
            return false;
        }
    
        Customer o = (Customer) c;
    
        return this.name.equals(o.getName());
    
    }
}