// Hammad Siddiqui
#include <iostream>  
#include <string>  

using namespace std;  

class Level {  
public:  
    string name;  
    int difficulty; 

    Level(string n, int diff)   
        : name(n), difficulty(diff) {}  
};  

class VideoGame {  
private:  
    string title;  
    string genre;  
    Level* levels[5];   
    int levelCount;  

public:  
    VideoGame(string t, string g)   
        : title(t), genre(g), levelCount(0) {  
         
        for (int i = 0; i < 5; i++) {  
            levels[i] = nullptr;   
        }  
    }  

    ~VideoGame() {  
          
        for (int i = 0; i < levelCount; ++i) {  
            delete levels[i];  
        }  
    }  

    void addLevel(string name, int difficulty) {  
        if (levelCount < 5) {  
            levels[levelCount++] = new Level(name, difficulty);  
        } else {  
            cout << "Maximum limit reached." << endl;  
        }  
    }  

    void displayDetails() const {  
        cout << "Video Game Title: " << title << endl;  
        cout << "Genre: " << genre << endl;  
        cout << "Levels: " << endl;  
        for (int i = 0; i < levelCount; ++i) {  
            cout << " - Level Name: " << levels[i]->name   
                 << ", Difficulty: " << levels[i]->difficulty << endl;  
        }  
    }  
};  

int main() {  
   
    VideoGame game("Epic Adventure", "Action SciFi");  

     
    game.addLevel("Forest of Dark", 3);  
    game.addLevel("Sea of Death", 5);  
    game.addLevel("Mountain of Warriors", 7);  

     
    game.displayDetails();  

    return 0;  
}  
