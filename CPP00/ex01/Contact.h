//
// Created by acaffard on 8/13/24.
//

#ifndef CPPS_CONTACT_H
#define CPPS_CONTACT_H

# include <iostream>
# include <string>
# include "Contact.h"

class Contact {
    private :
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    public :
        Contact();
        ~Contact();
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getPhoneNumber();
        std::string getSecret();
        void        setFirstName(std::string value);
        void        setLastName(std::string value);
        void        setNickName(std::string value);
        void        setPhoneNumber(std::string value);
        void        setSecret(std::string value);
        void        print();
};

#endif //CPPS_CONTACT_H
