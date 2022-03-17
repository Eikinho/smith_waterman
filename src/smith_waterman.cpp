#include "aux.hpp"



int main()
{
    // reading .txt file that contains the both sequencies. Create the cursor. 
    Cursor cursor = init();
    
    cursor.smith_waterman.matrix = create_matrix(cursor.one, cursor.two);
    cout_sequency_init(cursor.one);
    cout_sequency_init(cursor.two);
    cout << '\n';
    cout << "---------------------------------" << '\n';
    cout << '\n';

    cout << "Matrix Output:" << '\n';
    cout << '\n';

    cursor.smith_waterman.matrix = smith_waterman(cursor);
    cout_matrix(cursor);
    
    cout << '\n';
    cout << "---------------------------------" << '\n';
    cout << '\n';

    cursor.smith_waterman.score = score(cursor);

    cout << "Score: " << cursor.smith_waterman.score << '\n';
    return 0;
} 