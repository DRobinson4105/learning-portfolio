package functionalinterface;

import java.util.function.Predicate;

public class _Predicate {
    public static void main(String[] args) {
        String phoneNumber = "07000000000";
        System.out.println(isPhoneNumberValid(phoneNumber));
        System.out.println(isPhoneNumberValidPredicate.test(phoneNumber));

        String phoneNumber2 = "123";
        System.out.println(isPhoneNumberValid(phoneNumber2));
        System.out.println(isPhoneNumberValidPredicate.test(phoneNumber2));
    }

    static Predicate<String> isPhoneNumberValidPredicate = phoneNumber ->
            phoneNumber.startsWith("07") && phoneNumber.length() == 11;

    static boolean isPhoneNumberValid(String phoneNumber) {
        return phoneNumber.startsWith("07") && phoneNumber.length() == 11;
    }
}
