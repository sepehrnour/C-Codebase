#ifndef INVALIDINPUT_H
#define INVALIDINPUT_H

class InvalidInput
{
    private:
    string message;

    public:
    InvalidInput(string input) : message("Invalid input "" + input + ""."){};
    void print_reason()
    {
        cout << message << endl;
    }
};

#endif