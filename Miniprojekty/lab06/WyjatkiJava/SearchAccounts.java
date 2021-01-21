import java.util.ArrayList;

interface SearchAccounts {
    Account findByNumber(int number)
        throws AccountNotFoundException;
    ArrayList<Account> findAllCustomerAccounts(Customer cust)
        throws AccountNotFoundException;
}