import java.util.ArrayList;

public class Bank implements SearchAccounts , SearchCustomers {
    ArrayList<Customer> customers = new ArrayList<Customer>();
    ArrayList<Account> accounts = new ArrayList<Account>();

    @Override
    public Customer findByName(String name)
        throws CustomerNotFoundException {
            for(Customer tmp : customers) {
                if(tmp.getName().equals(name)) {
                    return tmp;
                }
            }
            throw new CustomerNotFoundException(name);
    }

    @Override
    public Account findByNumber(int num)
        throws AccountNotFoundException {
            for( Account tmp : accounts) {
                if(tmp.getNumber() == num) {
                    return tmp;
                }
            }
        throw new AccountNotFoundException(num);
    }

    @Override
    public ArrayList<Account> findAllCustomerAccounts(Customer cust)
        throws AccountNotFoundException {
            ArrayList<Account> all = new ArrayList<>();
            for(Account tmp : accounts) {
                if(tmp.getCustomer() == cust) {
                    all.add(tmp);
                }
            }
            if(all.isEmpty()) {
                throw new AccountNotFoundException(cust);
            }
            else {
                return all;
            }
    }

    public Customer addNewClient(String n, String fn, int p) 
        throws AddNewCustomerFailedException {
        for(Customer tmp : customers) {
            if(tmp.getPESEL() == p) {
                throw new AddNewCustomerFailedException(n, fn, p);
            }
        }
        Customer c = new Customer(n, fn, p);
        customers.add(c);
        return c;
    }

    public Account addNewAccount(int an, Customer c, double b, int p, String l)
        throws AddNewAccountFailedException {
        for(Account tmp : accounts) {
            if(tmp.getNumber() == an) {
                throw new AddNewAccountFailedException(an, c, b, p, l);
            }
        }
        Account a = new Account(an, c, b, p, l);
        accounts.add(a);
        return a;
    }

    public static void main(String[] args) throws Throwable {
        Bank bank = new Bank();
        try {
           Customer c = bank.addNewClient("Flinn", "Aron", 5585);
           Account a = bank.addNewAccount(1, c, (double)0, 5565, "test");
           Account test = bank.findByNumber(a.getNumber());
           if(test == a) {
            System.out.println("Istnieje!");
           }
           else {
            System.out.println("Nie istnieje!");
           }
           Customer found = bank.findByName("Flinn2");
           if(found == c) {
            System.out.println("Istnieje!");
           }
           else {
            System.out.println("Nie istnieje!");
           }

           a.login("test", 5565);
           ArrayList<Account> list = bank.findAllCustomerAccounts(c);

        }
        catch(AccountLoginFailedException e) {
            e.printStackTrace();
        }
        catch(AccountNotFoundException e) {
            e.printStackTrace();
        }
        catch(AddNewAccountFailedException e) {
            e.printStackTrace();
        }
        catch(AddNewCustomerFailedException e) {
            e.printStackTrace();
        }
        catch(CustomerNotFoundException e){
            e.printStackTrace();
            e.fillInStackTrace();
            throw e;
        }
        catch(Exception e) {
            e.printStackTrace();
        }
        finally {

        }
    }

    
}
    