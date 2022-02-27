#include <iostream>
#include <cpr/cpr.h>

using std::cout;
using std::cin;
using std::string;

int main() {

    string urlAddr = "http://httpbin.org";

    string answer;
    cpr::Response resp;

    while(true)
    {
        cout << "\nEnter one of the commands\n"
                "\"get\", \"post\", \"put\", \"delete\", \"patch\" or \"ext\".\n"
                "Your command: ";
        cin >> answer;

        if(answer == "ext")
        {
            cout << "\nExit from the program!";
            break;
        }

        else if(answer == "get")
            resp = cpr::Get(cpr::Url(urlAddr + "/get"));

        else if(answer == "post")
            resp = cpr::Post(cpr::Url(urlAddr + "/post"));

        else if(answer == "put")
            resp = cpr::Put(cpr::Url(urlAddr + "/put"));

        else if(answer == "delete")
            resp = cpr::Delete(cpr::Url(urlAddr + "/delete"));

        else if(answer == "patch")
            resp = cpr::Patch(cpr::Url(urlAddr + "/patch"));

        else
        {
            cout << "\nIncorrect input. Try again!";
            continue;
        }

        cout << "\n\n" << resp.text;
    }

    return 0;
}