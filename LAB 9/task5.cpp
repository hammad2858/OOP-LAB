#include<iostream>
using namespace std;

class Shipment{
    protected:
    string TrackingNumber;
    double weight;
    public:
    Shipment(string tn,double w):TrackingNumber(tn),weight(w){}
    virtual double estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;
};

class AirFreight:public Shipment{
    public:
    AirFreight(string tn , double w):Shipment(tn,w){}
    double estimateDeliveryTime()override{
        return 1.5+(weight*0.1);
    }

    void showDetails()override{
       cout << "Tracking Number: " << TrackingNumber << "\n";
        cout << "Weight: " << weight << " kg\n";
    }
};
class GroundShipment : public Shipment {
public:
    GroundShipment(string tn, double w) : Shipment(tn, w) {}

    void showDetails() override {
        cout << "Tracking Number: " << TrackingNumber << "\n";
        cout << "Weight: " << weight << " kg\n";
    }

    double estimateDeliveryTime()  override {
        
        return 5.0 + (weight * 0.2); 
    }
};

int main (){
    Shipment* shipment[2];

    shipment[0] = new AirFreight("PK-658",10.6);
    shipment[1] = new GroundShipment("GS-369",12.5);

    for (int i=0;i<2;i++){
        shipment[i]->showDetails();
        cout << "Estimated Delivery Time: " << shipment[i]->estimateDeliveryTime() << " hours"<<endl;;
    }
    for (int i = 0; i < 2; ++i) {
        delete shipment[i];
    }
          return 0;
}
