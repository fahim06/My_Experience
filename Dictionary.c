
#include <stdio.h>

#include <malloc.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

#include<conio.h>

#include<windows.h>

#include<strings.h>

struct node

{

    char data [ 20 ] ;

    char m [ 5 ] [ 20 ];

    int mcount ; //Meaning counter (Here we are taking 5 individual lines for each word meaning)

    struct node * next ;

} ;



struct node * dic [ 26 ] ; //Since English-Alphabets has 26 Characters


//Function ProtoType

void Insert_Dictionary ( char * ) ;

int  Search_Dictionary ( char * ) ;

void display( ) ;

void deldictionary( ) ;



void main( )

{

    char word [ 20 ];

    int input;

    int i ;


    system("cls");//Clearing The Screen


    //Startup Screen
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tPLEASE WAIT OUR DICTIONARY IS OPENING....\n\n");
    printf("\t\t\t");
    for(int loading=0; loading<70; loading++)
    {

        Sleep(40);
        printf("%c",178);


    }
    system("cls");



    while (1)  //1=True


    {

        system("cls");

        printf ( "\n\n\t\t/*\\/*\\/*\\/*\\ Welcome To Dictionary /*\\/*\\/*\\/*\\\n" ) ;

        printf("\n \n");

        printf ( "\n\t\t[1] Enter A Word To Add In The Dictionary\n" ) ;

        printf ( "\t\t[2] Search A Word From Dictionary\n" ) ;

        printf ( "\t\t[3] Display Complete Dictionary\n" ) ;

        printf("\n \n");

        printf ( "\t\t[0] Exit Dictionary" ) ;

        printf ( "\n\n\t\t>>>>>> <ENTER Your Choice> <<<<<<\n\n") ;

        //User Input

        scanf ( "%d", &input ) ;



        switch ( input )

            //Using Switch-case for performing operations

        {

        case 1 :



            printf ( "\nEnter any word : " ) ;

            fflush ( stdin ) ; //Clear_Output Buffer

            gets ( word ) ;

            Insert_Dictionary ( word ) ;



            break ;



        case 2 :



            printf ( "\nEnter the word to Search: " ) ;

            fflush ( stdin ) ;

            gets ( word ) ;  //Get Character Input From User

            i = Search_Dictionary ( word ) ;

            if ( ! i )

                printf ( "Word does not exist." ) ;

            getch ();



            break ;



        case 3 :



            display( ) ;   //Call Display Function

            getch ();



            break ;



        case 0 :
            system("cls");

            //Closing Screen
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t      EXITING...\n\n");
            printf("\t\t\t");
            for(int loading=0; loading<70; loading++)
            {

                Sleep(30);
                printf("%c",178);


            }
            system("cls");
            getch();

            deldictionary( ) ;

            exit ( 0 ) ;



        default :



            printf ( "\nWrong Choice" ) ;

        }

    }

}



void Insert_Dictionary ( char * str )

{
    //Last Insert Algorithm

    int i, j = toupper ( str [ 0 ] ) - 65 ;//For UpperCase Alphabets

    struct node * r, * temp = dic [ j ], * q ;

    char mean [ 5 ] [ 20 ], ch = 'y' ;



    i = Search_Dictionary ( str ) ;

    if ( i )

    {

        printf ( "\nWord already exists in the Dictionary." ) ;

        getch ();

        return ;

    }

    q = ( struct node * ) malloc ( sizeof ( struct node ) ) ;

    strcpy ( q -> data, str ) ;

    q -> next = NULL ;



    for ( i = 0 ; tolower ( ch ) == 'y' && i < 5 ; i++ )//For LowerCase Alphabets

    {

        fflush ( stdin ) ;

        printf ( "\n\nEnter the meaning(s) : " ) ;

        gets ( mean [ i ] ) ;

        strcpy ( q -> m [ i ], mean [ i ] ) ;

        if ( i != 4 )

            printf ( "\nDo You Want To Add  more meanings (y/n) " ) ;

        else

            printf ( "You cannot enter more than 5 meanings." ) ;

        fflush ( stdin ) ;

        ch = getche (); //For Working With Characters

    }



    q -> mcount = i ;

    if ( dic [ j ] == NULL || strcmp ( dic [ j ] -> data, str ) > 0 )
    {

        r = dic [ j ] ;

        dic [ j ] = q ;

        q -> next = r ;

        return ;

    }



    else

    {

        while ( temp != NULL )

        {

            if ( ( strcmp ( temp -> data, str ) < 0 ) && ( ( strcmp ( temp -> next -> data, str ) > 0 ) || temp -> next == NULL ) )

            {

                q -> next = temp -> next ;

                temp -> next = q ;

                return ;

            }

            temp = temp -> next ;

        }

    }

}



int Search_Dictionary ( char *str )

{

    struct node *n ;

    char temp1 [ 20 ];

    char temp2 [ 20 ];

    int i ;



    n = dic [ toupper ( str [ 0 ] ) - 65 ] ;

    strcpy ( temp2, str ) ;

    strupr ( temp2 ) ;



    while ( n != NULL )

    {

        strcpy ( temp1, n -> data ) ;



        if (  strcmp ( strupr ( temp1 ), temp2 ) == 0 ) //Comparing Input and Stored Data Using 'strcmp' function


        {
            int i, j ;



            printf ( "Word\t\tMeaning\n" ) ;

            for ( i = 0 ; i <= 30 ; i++ )

                printf ( "-" ) ;//For Decorations


            printf ( "\n%s\t\t%s\n", n -> data, n -> m [ 0 ] ) ;

            for ( i = 1 ; i < n -> mcount ; i++ )

                printf ( "\n\t\t%s\n", n -> m [ i ] ) ;

            return 1 ;

        }

        n = n -> next ;

    }

    return 0 ;

}



void display( )

{
    //Display Function

    struct node *n ;

    int i, j ;



    printf ( "Word\t\tMeaning\n" ) ;

    for ( i = 0 ; i <= 30 ; i++ )

        printf ( "-" ) ;//For Decorations





    for ( i = 0 ; i <= 25 ; i++ )

    {

        n = dic [ i ] ;

        while ( n != NULL )

        {

            printf ( "\n%s\t\t%s\n", n -> data, n -> m [ 0 ] ) ;

            for ( j = 1 ; j < n -> mcount ; j++ )

                printf ( "\n\t\t%s\n", n -> m [ j ] ) ;

            n = n -> next ;

        }

    }

}

void deldictionary( )

{
    //Clean Dictionary Space

    struct node *n, *t ;

    int i ;



    for ( i = 0 ; i <= 25 ; i++ )

    {

        n = dic [ i ] ;

        while ( n != NULL )

        {

            t = n -> next ;

            free ( n ) ;// Deallocates the memory previously allocated by a call to calloc, malloc, or realloc

            n = t ;

        }

    }

}
