package functionalinterface;

import java.util.function.Consumer;

public class _Consumer {
    public static void main(String[] args) {
        Customer maria = new Customer("Maria", "99999");
        greetCustomer(maria);
        greetCustomerConsumer.accept(maria);
    }

    static void greetCustomer(Customer customer) {
        System.out.println("Hello " + customer.name +
                ", thanks for registering phone number " + customer.phoneNumber);
    }

    static Consumer<Customer> greetCustomerConsumer = customer -> System.out.println("Hello " +
            customer.name + ", thanks for registering phone number " + customer.phoneNumber);

    static class Customer {
        private final String name;
        private final String phoneNumber;

        Customer(String name, String phoneNumber) {
            this.name = name;
            this.phoneNumber = phoneNumber;
        }
    }
}
