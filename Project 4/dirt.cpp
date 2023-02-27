// Exception
class InvalidInput
{
private:
  string message;

public:
  InvalidInput(string s)
  {
    message = s;
  }
  void reason()
  {
    cout << "Invalid input <" << message << ">." << endl;
  }
};

float round(float var)
{
  // 37.66666 * 100 =3766.66
  // 3766.66 + .5 =3767.16 for rounding off value
  // then type cast to int so value is 3767
  // then divided by 100 so the value converted into 37.67
  float value = (int)(var * 100 + .5);
  return (float)value / 100;
}

// 1. DeliveryOrder class
class DeliveryOrder
{
private:
  string name, address1, address2, phone;
  int day, month, year;
  float miles;
  static int orderCount;

public:
  static const float taxRate = 0.0887, deliveryRate = 0.5;
  float balance;

  // constructors
  DeliveryOrder(string sname, string saddress1, string saddress2, string sphone, int sday, int smonth, int syear, float smiles)
  {

    name = sname;
    address1 = saddress1;
    address2 = saddress2;
    phone = sphone;
    day = sday;
    month = smonth;
    year = syear;
    miles = smiles;
    balance = 0;
    orderCount++;
  }

  // printReceipt function
  const printReceipt()
  {
    cout << "Order Detail:" << "\n";
    cout << "\tName: " << name << "\n";
    cout << "\tDate: " << date << "\n";
    cout << "\tPhone: " << phone << "\n";
    cout << "\tOrder Balance: $" << orderBalance << endl;
  }

  // getTotalBalance function
  const float getTotalBalance()
  {
    return orderBalance * (1 + taxRate) + miles * deliveryRate;
  }

  // static getOrderCount function
  static getOrderCount()
  {

    return orderCount;
  }

  // pure virtual discount function
  virtual float discount()
  {
  }

  // destructor
  ~DeliveryOrder()
  {
    cout << "DeliveryOrder destroyed.\n";
  }
};

int DeliveryOrder::orderCount = 0;


