#include <bits/stdc++.h>
#include <time.h>
#include <string.h>
using namespace std;

/*((((((((********%%%%%%%%********--------    ALL FUNCTION DECLARATION    --------********%%%%%%%%********))))))))*/

void make_grid();
void viewGrid(char);
bool pos_check(int);
void updated_sample(int);
int random();
int exact_pos_x(int);
int exact_pos_y(int);
bool winner(string);
void options();

/*((((((((********%%%%%%%%********--------    GLOBAL COMPONENTS    --------********%%%%%%%%********))))))))*/

int range = 9; // for reducing the number of choice of cell number in auto mode as the game goes on
int Win;       // for winning

int sample_set[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // decleared all positions
int size = 9;

string str[] = {"123", "456", "789", "147", "258", "369", "159", "357"}; // Pre-defined win cases to be compared
char grid[17][17];                                                       // Dimension of the grid

string str1; // to check win combinaton for player 1 entries
string str2; // to check win combinaton for player 2 entries

/*((((((((********%%%%%%%%********--------    ALL FUNCTIONS DEFINITION    --------********%%%%%%%%********))))))))*/

// 1. creating grid

void make_grid()
{
    int temp_count = 0;
    for (int i = 0; i < 17; i++)
    {
        if (temp_count == 5)
        {
            temp_count = -1;
            for (int j = 0; j < 17; j++)
                grid[i][j] = 'O';
        }
        else
        {
            int temp_count1 = 0;
            for (int j = 0; j < 17; j++)
            {
                if (temp_count1 == 5)
                {
                    grid[i][j] = 'O';
                    temp_count1 = -1;
                }
                else
                    grid[i][j] = ' ';
                temp_count1++;
            }
        }
        temp_count++;
    }
}
// 2. Function to view the status of the grid

void viewGrid(char grid[17][17])
{
    cout << "---------------------------------------------------------------------------------------------------------------------------------------"
         << "\n\n";
    for (int i = 0; i < 17; i++)
    {
        cout << setw(50);
        for (int j = 0; j < 17; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
    cout << "---------------------------------------------------------------------------------------------------------------------------------------"
         << "\n\n";
}

// 3. for checking the available positions

bool pos_check(int place)
{
    bool flag = false;
    for (int i = 0; i < size; i++)
    {
        if (sample_set[i] == place)
            flag = true;
    }
    return flag;
}

// 4. for updating the set of available positions

void updated_sample(int place)
{
    for (int i = 0; i < size; i++)
    {
        if (sample_set[i] == place)
        {
            swap(sample_set[i], sample_set[size - 1]);
            sample_set[size - 1] = 0;
            size = size - 1;
        }
    }
    sort(sample_set, sample_set + size);
    range--;
}

// 5. generates a random number

int random()
{
    srand(time(NULL));

    int value = sample_set[rand() % range];
    for (int i = 0; i < size; i++)
    {
        if (sample_set[i] == value)
        {
            swap(sample_set[i], sample_set[size - 1]);
            sample_set[size - 1] = 0;
            size = size - 1;
        }
    }
    sort(sample_set, sample_set + size);
    return value;
}

// 6. generates the exact start position on x-axis for cross or cicle

int exact_pos_x(int pos)
{
    if (pos == 1 || pos == 2 || pos == 3)
        return 1;

    if (pos == 4 || pos == 5 || pos == 6)
        return 7;

    if (pos == 7 || pos == 8 || pos == 9)
        return 13;
    return 0;
}

// 7. generates the exact start position on y axis for cross or cicle

int exact_pos_y(int pos)
{
    if (pos == 1 || pos == 4 || pos == 7)
        return 1;

    if (pos == 2 || pos == 5 || pos == 8)
        return 7;

    if (pos == 3 || pos == 6 || pos == 9)
        return 13;
    return 0;
}

// 8. for calculating the result

bool winner(string combo)
{
    if (combo.length() < 3)
        return 0;
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int k = 0; k < combo.size(); k++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (int(str[i][j]) == int(combo[k]))
                {
                    count++;
                    break;
                }
            }
            if (count == 3)
                return 1;
        }
        count = 0;
    }
    return 0;
}

// 9. show options
void options()
{
    cout << endl
         << setw(60);
    for (int i = 0; i < size; i++)
        cout << sample_set[i] << "  ";
    cout << endl
         << endl;
}
/*((((((((********%%%%%%%%****----------------    MAIN FUNCTION    ----------------****%%%%%%%%********))))))))*/

int main()
{
    int choose;      // variable to select whether 1 or 2 player
    string st1, st2; // variable for name of two
    char sign;       // to store whether 'X' or 'O'
    string st = {"[*---------$$$$$$   TIC TAC TOE   $$$$$$---------*]"};

    cout << "\n\n"
         << setw(90) << st << "\n\n"; // Title
    cout << "\n\n"
         << setw(70) << "ENTER YOUR CHOICE";
    cout << "\n\n"
         << setw(60) << "1. SINGLE PLAYER" << setw(20) << "2. MULTI PLAYER"
         << "\n\n";
    cin >> choose; //input choice

    bool condition = true;
    while (condition) //condition to eliminate wrong choice i.e. numbers other than 1 or 2
    {
        if (choose == 1) //for 1 player (vs computer)
        {
            condition = false; //breaking the while loop
            st2 = {"COMPUTER"};
            cout << "\n\n"
                 << setw(70)
                 << "ENTER YOUR NAME:  ";
            cin >> st1;
            cout << "\n\n"
                 << setw(60) << st1 << "  V/S  "
                 << st2
                 << "\n\n";
            cout << setw(70) << " PICK ONE 'X' OR 'O' ";
            cin >> sign;
            bool p = true;
            while (p)
            {
                if (sign == 'X' || sign == 'x')
                {
                    cout << "\n\n"
                         << setw(55) << st1 << " took 'X' while " << st2 << " took 'O'."
                         << "\n\n";
                    p = false;
                }
                else if ((sign == 'O' || sign == 'o'))
                {
                    cout << "\n\n"
                         << setw(55) << st1 << " took 'O' while " << st2 << " took 'X'."
                         << "\n\n";
                    p = false;
                }
                else
                {
                    cout << setw(70) << "WRONG.. TRY AGAIN"
                         << "\n\n";
                    p = true;
                    cin >> sign;
                }
            }
        }
        else if (choose == 2) //for 2 players
        {
            condition = false; //breaking the while loop
            cout << "\n\n"
                 << setw(70)
                 << "ENTER PLAYER-1 NAME:  ";
            cin >> st1;
            cout << "\n\n"
                 << setw(70)
                 << "ENTER PLAYER-2 NAME:  ";
            cin >> st2;
            cout << "\n\n"
                 << setw(60) << st1 << "  V/S  " << st2 << "\n\n";
            cout << "\n\n"
                 << setw(55) << st1 << " take 'X' while " << st2 << " take 'O'."
                 << "\n\n";
        }
        else //wrong choice
        {
            cout << "\n\n"
                 << setw(75) << "WRONG CHOICE.. ENTER AGAIN!"
                 << "\n\n";
            cout << "\n\n"
                 << setw(70) << "ENTER YOUR CHOICE";
            cout << "\n\n"
                 << setw(60) << "1. SINGLE PLAYER" << setw(20) << "2. MULTI PLAYER"
                 << "\n\n";
            cin >> choose;
        }
    }

    make_grid();    // making the grid
    viewGrid(grid); // view the grid status

    int place; // to consume the cell number
    int who;   // to change the turn between the players
    bool flag; // in auto mode to distinguish the computer's turn and user's turn

    if (choose == 1) // if playing against computer
    {
        if (sign == 'O' || sign == 'o')
        {
            flag = true;
            who = 1;
            cout << "\n\n"
                 << setw(75) << "COMPUTER's TURN  " << endl
                 << endl;
            place = random();
            str2 = str2 + to_string(place);
        }
        else
        {
            flag = false;
            who = 1;
            cout << "\n\n"
                 << setw(90) << "YOUR TURN FIRST, ENTER A NUMBER BETWEEN 1-9:  ";
            cin >> place;
            updated_sample(place);
            str1 = str1 + to_string(place);
        }
    }
    else // if playing against person
    {
        who = 1;
        cout << "\n\n"
             << setw(50) << st1 << "'s "
             << "TURN, ENTER A NUMBER BETWEEN 1-9:  ";
        ;
        cin >> place;
        updated_sample(place);
        str1 = str1 + to_string(place);
    }

    int chance = 9;
    while (chance)
    {
        if (who)
        {
            int x_axis = exact_pos_x(place);
            int y_axis = exact_pos_y(place);
            int upto_x = x_axis + 3;
            int upto_y = y_axis + 3;
            int centre_x = ((2 * x_axis) + 2) / 2;
            int centre_y = ((2 * y_axis) + 2) / 2;
            grid[centre_x][centre_y] = 'X';
            for (int i = x_axis; i < upto_x; i++)
            {
                for (int j = y_axis; j < upto_y; j++)
                {
                    if (i % 2 != 0 && j % 2 != 0)
                        grid[i][j] = '*';
                }
            }
            who = !who;
        }
        else
        {
            int x_axis = exact_pos_x(place);
            int y_axis = exact_pos_y(place);
            int upto_x = x_axis + 3;
            int upto_y = y_axis + 3;
            int j, i;
            for (j = y_axis; j < upto_y; j++)
            {
                grid[x_axis][j] = '*';
            }
            j--;
            for (i = x_axis; i < upto_x; i++)
            {
                grid[i][j] = '*';
            }
            i--;
            while (j != y_axis)
            {
                grid[i][j] = '*';
                j--;
            }
            while (i != x_axis)
            {
                grid[i][j] = '*';
                i--;
            }
            who = !who;
        }

        viewGrid(grid);
        bool win = winner(str1);
        if (win)
        {
            Win = 1;
            break;
        }
        win = winner(str2);
        if (win)
        {
            Win = 2;
            break;
        }
        chance--;

        if (chance == 0)
            break;

        options();

        if (who)
        {
            if (choose == 1)
            {
                if (flag == true)
                {
                    cout << "\n\n"
                         << setw(75) << "COMPUTER's TURN " << endl
                         << endl;
                    place = random();
                    str2 = str2 + to_string(place);
                }
                else
                {
                    bool check = 0;
                    while (!check)
                    {
                        cout << "\n\n"
                             << setw(50) << st1 << "'s "
                             << "TURN, ENTER A NUMBER FROM REMAINING:  ";
                        cin >> place;
                        check = pos_check(place);
                        if (!check)
                            cout << "\n\n"
                                 << setw(75) << "INVALID POSITION..";
                        else
                            updated_sample(place);
                    }
                    str1 = str1 + to_string(place);
                }
            }
            else
            {
                bool check = 0;
                while (!check)
                {
                    cout << "\n\n"
                         << setw(50) << st1 << "'s "
                         << "TURN, ENTER A NUMBER FROM REMAINING:  ";
                    cin >> place;
                    check = pos_check(place);
                    if (!check)
                        cout << "\n\n"
                             << setw(75) << "INVALID POSITION..";
                    else
                        updated_sample(place);
                }
                str1 = str1 + to_string(place);
            }
        }
        else
        {
            if (choose == 1)
            {
                if (flag == true)
                {
                    bool check = 0;
                    while (!check)
                    {
                        cout << "\n\n"
                             << setw(50) << st1 << "'s "
                             << "TURN, ENTER A NUMBER FROM REMAINING:  ";
                        cin >> place;
                        check = pos_check(place);
                        if (!check)
                            cout << "\n\n"
                                 << setw(75) << "INVALID POSITION..";
                        else
                            updated_sample(place);
                    }
                    str1 = str1 + to_string(place);
                }
                else
                {
                    cout << "\n\n"
                         << setw(75) << "COMPUTER's TURN " << endl
                         << endl;
                    place = random();
                    str2 = str2 + to_string(place);
                }
            }
            else
            {
                bool check = 0;
                while (!check)
                {
                    cout << "\n\n"
                         << setw(50) << st2 << "'s "
                         << "TURN, ENTER A NUMBER FROM REMAINING:  ";
                    cin >> place;
                    check = pos_check(place);
                    if (!check)
                        cout << "\n\n"
                             << setw(75) << "INVALID POSITION..";
                    else
                        updated_sample(place);
                }
                str2 = str2 + to_string(place);
            }
        }
    }
    if (Win == 1)
        cout << "\n\n"
             << setw(60) << st1 << " WON!!!!!!!! ";
    else if (Win == 2)
        cout << "\n\n"
             << setw(60) << st2 << " WON!!!!!!!! ";
    return 0;
}