#include <iostream>
#include <list>
#include <string>
using namespace std;

class YoutubeChannel {
private:
    string Name;
    string OwnerName;
    static int SubscriberCount;
    list<string> PublishedVideoTitles;

public:
    // Constructor
    YoutubeChannel(string name, string ownerName) {
        Name = name;
        OwnerName = ownerName;
    }

    // Accessors
    string getName() const {
        return Name;
    }

    string getOwnerName() const {
        return OwnerName;
    }

    static int getSubscriberCount() {
        return SubscriberCount;
    }

    list<string> getPublishedVideoTitles() const {
        return PublishedVideoTitles;
    }

    // Mutators 
    void setName(const string& name) {
        Name = name;
    }

    void setOwnerName(const string& ownerName) {
        OwnerName = ownerName;
    }

    void Subscribe() {
        SubscriberCount++;
    }

    void Unsubscribe() {
        if (SubscriberCount > 0) {
            SubscriberCount--;
        }
    }

   
    void PublishVideo(const string& title) {
        PublishedVideoTitles.push_back(title);
    }

    void GetInfo() const {
        cout << "Name: " << Name << endl;
        cout << "Owner Name: " << OwnerName << endl;
        cout << "Number of Subscribers: " << SubscriberCount << endl;
        cout << "Videos: " << endl;
        for (const string& title : PublishedVideoTitles) {
            cout << title << endl;
        }
    }
};

int YoutubeChannel::SubscriberCount = 0;

int main() {
    YoutubeChannel ytChannel("Tech Insight", "Joshua Darrah");

    ytChannel.PublishVideo("Understanding Encapsulation in C++");

    ytChannel.Unsubscribe();
    ytChannel.GetInfo();

    for (int i = 0; i < 20; i++) {
        ytChannel.Subscribe();
    }

    cout << "\nAfter adding 20 subscribers:\n";
    ytChannel.GetInfo();

    return 0;
}
