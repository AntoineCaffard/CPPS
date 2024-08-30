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
        void        setFirstName();
        void        setLastName();
        void        setNickName();
        void        setPhoneNumber();
        void        setSecret();
        void        print();
};

#endif //CPPS_CONTACT_H
