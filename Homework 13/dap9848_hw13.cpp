#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

const int GRID_SIZE = 20;
const int DOODLEBUG_INITIALIZE = 5;
const int ANT_INITALIZE = 100;
const int DOODLEBUG_BREED_TIME = 8;
const int ANT_BREED_TIME = 3;
const char DOODLEBUG_ID = 'D';
const char ANT_ID = 'A';



class Organism {
protected:
    int row, col;         // Position on the grid
    int timeSurvived;     // Steps survived
    int breedTimer;       // Steps until breeding

public:
    Organism(int r, int c) : row(r), col(c), timeSurvived(0), breedTimer(0) {}
    virtual ~Organism() = default;

    // Accessors
    int getRow() const { return row; }
    int getCol() const { return col; }
    int getTimeSurvived() const { return timeSurvived; }
    int getBreedTimer() const { return breedTimer; }
    virtual char getType() const { return ' '; }

    // Mutators
    void setPosition(int r, int c) { row = r; col = c; }
    void incrementSurvival() { timeSurvived++; }
    void resetBreedTimer() { breedTimer = 0; }

    // Virtual methods to override in derived classes
    virtual void move(Organism* grid[GRID_SIZE][GRID_SIZE]) = 0;
    virtual void breed(Organism* grid[GRID_SIZE][GRID_SIZE]) = 0;
    virtual bool isStarving() { return false; }
};

class Ant : public Organism {
public:
    Ant(int r, int c) : Organism(r, c) {}

    char getType() const { return ANT_ID; }

    void move(Organism* grid[GRID_SIZE][GRID_SIZE]);
    void breed(Organism* grid[GRID_SIZE][GRID_SIZE]);
    bool isStarving() { return false; }
};

class Doodlebug : public Organism {
private:
    int starveTimer; // Steps without eating an ant

public:
    Doodlebug(int r, int c) : Organism(r, c), starveTimer(0) {}

    char getType() const { return DOODLEBUG_ID; }

    void move(Organism* grid[GRID_SIZE][GRID_SIZE]);
    void breed(Organism* grid[GRID_SIZE][GRID_SIZE]);
    bool isStarving() { return starveTimer >= 3; }
    void resetStarveTimer() { starveTimer = 0; }
};

int getRandomDirection() {
    return rand() % 4; // 0: Up, 1: Right, 2: Down, 3: Left
}

bool checkUsedDirection(vector<int> direction, int newDir){
    for (int i : direction){
        if (i == newDir)
            return true;
    }
    return false;
}

void Ant::move(Organism* grid[GRID_SIZE][GRID_SIZE]) {
    //Checks adjacent spaces
    for (int i = 0; i < 4; i++) {
        int direction = getRandomDirection();
        int newRow = row;
        int newCol = col;

        switch (direction) {
        case 0: //Up
            newRow -= 1;
            break;
        case 1: //Right
            newCol += 1;
            break;
        case 2: //Down
            newRow += 1;
            break;
        case 3: //Left
            newCol -= 1;
            break;
        }

        //Checks if space empty and out of bounds
        if (newRow >= 0 && newRow < GRID_SIZE && newCol >= 0 && newCol < GRID_SIZE && grid[newRow][newCol] == nullptr) {
            grid[newRow][newCol] = this;
            grid[row][col] = nullptr;
            setPosition(newRow, newCol);
            break;
        }
    }

    incrementSurvival();
    breedTimer++;
}

void Ant::breed(Organism* grid[GRID_SIZE][GRID_SIZE]) {
    if (breedTimer < ANT_BREED_TIME) 
        return; //exits function if breed time has not meet

    else {
        vector<int> usedDirections;
        for (int i = 0; i < 4; i++) {
            int direction = getRandomDirection();
            while (checkUsedDirection(usedDirections, direction))
                direction = getRandomDirection();
            usedDirections.push_back(direction);

            int newRow = row;
            int newCol = col;

            switch (direction) {
            case 0: //Up
            newRow -= 1;
                break;
            case 1: //Right
            newCol += 1;
                break;
            case 2: //Down
            newRow += 1;
                break;
            case 3: //Left
            newCol -= 1;
                break;
            }

            if (newRow >= 0 && newRow < GRID_SIZE && newCol >= 0 && newCol < GRID_SIZE && grid[newRow][newCol] == nullptr) {
                grid[newRow][newCol] = new Ant(newRow, newCol);
                resetBreedTimer();
                break;
            }
        }
    }
}

void Doodlebug::move(Organism* grid[GRID_SIZE][GRID_SIZE]) {
    
    //Checks random adjacent spaces for ants
    vector<int> usedDirections;
    for (int i = 0; i < 4; i++) {
        int direction = getRandomDirection();
        while (checkUsedDirection(usedDirections, direction))
            direction = getRandomDirection();
        usedDirections.push_back(direction);
        
        int newRow = row;
        int newCol = col;

        switch (direction) {
        case 0: //Up
            newRow -= 1;
            break;
        case 1: //Right
            newCol += 1;
            break;
        case 2: //Down
            newRow += 1;
            break;
        case 3: //Left
            newCol -= 1;
            break;
        }

        if (newRow >= 0 && newRow < GRID_SIZE && newCol >= 0 && newCol < GRID_SIZE && grid[newRow][newCol] != nullptr) {
            if (grid[newRow][newCol]->getType() == ANT_ID) {
                delete grid[newRow][newCol];
                grid[newRow][newCol] = this;
                grid[row][col] = nullptr;
                setPosition(newRow, newCol);
                resetStarveTimer();
                incrementSurvival();
                this->breedTimer++;
                return;
            }
        }
    }

    //Randomly moves if no ants
    vector<int> usedDir;
    for (int i = 0; i < 4; i++) {
        int direction = getRandomDirection();
        while (checkUsedDirection(usedDir, direction))
            direction = getRandomDirection();
        usedDir.push_back(direction);
        int newRow = row;
        int newCol = col;

        switch (direction) {
        case 0: //Up
            newRow -= 1;
            break;
        case 1: //Right
            newCol += 1;
            break;
        case 2: //Down
            newRow += 1;
            break;
        case 3: //Left
            newCol -= 1;
            break;
        }

        if (newRow >= 0 && newRow < GRID_SIZE && newCol >= 0 && newCol < GRID_SIZE && grid[newRow][newCol] == nullptr) {
            grid[newRow][newCol] = this;
            grid[row][col] = nullptr;
            setPosition(newRow, newCol);
            break;
        }
    }

    starveTimer++;
    incrementSurvival();
    breedTimer++;
}

void Doodlebug::breed(Organism* grid[GRID_SIZE][GRID_SIZE]) {
    if (breedTimer < DOODLEBUG_BREED_TIME)
        return;
    
    else {
        vector<int> usedDirections;
        for (int i = 0; i < 4; i++) {
            int direction = getRandomDirection();
            while (checkUsedDirection(usedDirections, direction))
                direction = getRandomDirection();
            usedDirections.push_back(direction);

            int newRow = row;
            int newCol = col;

            switch (i) {
            case 0: //Up
                newRow -= 1;
                break;
            case 1: //Right
                newCol += 1;
                break;
            case 2: //Down
                newRow += 1;
                break;
            case 3: //Left
                newCol -= 1;
                break;
            }

            if (newRow >= 0 && newRow < GRID_SIZE && newCol >= 0 && newCol < GRID_SIZE && grid[newRow][newCol] == nullptr) {
                grid[newRow][newCol] = new Doodlebug(newRow, newCol);
                resetBreedTimer();
                break;
            }
        }
    }
}

void initializeGrid(Organism* grid[GRID_SIZE][GRID_SIZE]) {
    srand(time(0));

    int antCount = 0, doodlebugCount = 0;

    while (doodlebugCount < DOODLEBUG_INITIALIZE) {
        int r = rand() % GRID_SIZE, c = rand() % GRID_SIZE;
        if (grid[r][c] == nullptr) {
            grid[r][c] = new Doodlebug(r, c);
            doodlebugCount++;
        }
    }

    while (antCount < ANT_INITALIZE) {
        int r = rand() % GRID_SIZE, c = rand() % GRID_SIZE;
        if (grid[r][c] == nullptr) {
            grid[r][c] = new Ant(r, c);
            antCount++;
        }
    }
}

void runSimulation(Organism* grid[GRID_SIZE][GRID_SIZE]) {
    int timestep = 0;
    while (true) {

        for (int i = 0; i < 20; i++) //clears previous
            cout << ("\n");

        for (int r = 0; r < GRID_SIZE; r++) {
            for (int c = 0; c < GRID_SIZE; c++) {
                if (grid[r][c] != nullptr && grid[r][c]->getType() == DOODLEBUG_ID) {
                    grid[r][c]->move(grid);
                }
            }
        }

        for (int r = 0; r < GRID_SIZE; r++) {
            for (int c = 0; c < GRID_SIZE; c++) {
                if (grid[r][c] != nullptr && grid[r][c]->getType() == ANT_ID) {
                    grid[r][c]->move(grid);
                }
            }
        }

        for (int r = 0; r < GRID_SIZE; r++) {
            for (int c = 0; c < GRID_SIZE; c++) {
                if (grid[r][c] != nullptr && grid[r][c]->getType() == DOODLEBUG_ID)
                    grid[r][c]->breed(grid);
            }
        }

        for (int r = 0; r < GRID_SIZE; r++) {
            for (int c = 0; c < GRID_SIZE; c++) {
                if (grid[r][c] != nullptr && grid[r][c]->getType() == ANT_ID)
                    grid[r][c]->breed(grid);
            }
        }

        for (int r = 0; r < GRID_SIZE; r++) {
            for (int c = 0; c < GRID_SIZE; c++) {
                if (grid[r][c] != nullptr && grid[r][c]->isStarving()) {
                    delete grid[r][c];
                    grid[r][c] = nullptr;
                }
            }
        }

        cout << "Doodlebug/Ant World at Time " << timestep++ <<":\n";
        for (int i = 0; i < GRID_SIZE + 2; i++)
            cout << "_";
        cout << "\n";

        for (int r = 0; r < GRID_SIZE; r++) {
            cout << "|";
            for (int c = 0; c < GRID_SIZE; c++) {
                if (grid[r][c] == nullptr) {
                    cout << "-";
                } else if (grid[r][c]->getType() == ANT_ID) {
                    cout << "o";
                } else if (grid[r][c]->getType() == DOODLEBUG_ID) {
                    cout << "X";
                }
            }
            cout << "|\n";
        }

        for (int i = 0; i < GRID_SIZE + 2; i++)
            cout << "-";
        cout << "\n\n";

        cout << "Press Enter to continue or type 'end' to stop: ";
        string input;
        getline(cin, input);

        if (input == "end") {
            cout << "Simulation ended at Time " << --timestep << ".\n";
            break;
        }
    }
}

void cleanupGrid(Organism* grid[GRID_SIZE][GRID_SIZE]) {
    for (int r = 0; r < GRID_SIZE; r++) {
        for (int c = 0; c < GRID_SIZE; c++) {
            delete grid[r][c];
            grid[r][c] = nullptr;
        }
    }
}

int main() {
    Organism* grid[GRID_SIZE][GRID_SIZE] = {nullptr}; //constructs grid with no pointers
    initializeGrid(grid); //initializes grid with starting number of ants and doodlebugs as pointers (eg. 100 and 5)
    runSimulation(grid); //runs endless loop
    cleanupGrid(grid); //ensure no memory leaks

    return 0;
}
