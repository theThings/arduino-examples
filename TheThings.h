// Copyright (c) 2015 TheThings.iO
// This file is licensed under the MIT License
// http://opensource.org/licenses/MIT

#ifndef THETHINGS_H
#define THETHINGS_H

#include "Arduino.h"
#include "Ethernet.h"

class TheThings {
public:
    TheThings();
    TheThings(String);

    // Create a new thing passing it's existing token as an argument or leave
    // it empty to activate it later using "activate" function.
    String activate(String);

    // Return thing's token
    String getToken();

    // To write a variable into the theThings.iO cloud, call this function with
    // the value to write. This function can be called any times to add more
    // variables to be sent. Finally, call the "send" function to actually
    // write the values.

    // key: string
    // value: string
    void addValue(String, String);

    // key: string
    // value: number
    void addValue(String, double);

    // Actually send the values to theThings.iO. See function "addValue".
    String send();

    // Read a variable from the theThings.iO. If only the argument "key" is
    // specified, the last value will be returned. This function will return
    // "limit" number of values of the variable inside an array.
    //
    // key: name of the variable
    // limit: max number of values to return.
    // startDate and endDate format: YYYYMMDDHHmmss
    String read(String);
    String read(String, int);

    void subscribe();
    bool subscribed();
    int available();
    String read();

private:
    String token;
    String data;
    EthernetClient client;
    EthernetClient subscription_client;
    static byte server[];

    // Private functions
    bool POST(EthernetClient &, String, String &);
    bool GET(EthernetClient &, String &);
};

#endif // THETHINGS_H
