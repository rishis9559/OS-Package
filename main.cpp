#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

int logical_address[4][2],physical_address[4][2];

int p1[4],p2[5];
//no of pages - row, parameters - no of columns
int pg_1[4][2],pg_2[5][2];      //frame no and valid/invalid bit

int main_mem[50][1],mm_iter = 10;
int sec_mem[100][1],sm_iter = 15;

//add frames to main mem
//divide pages in pg
//create secondary mem

void overview();
void working();
void searcher(int);
void conclusion();
void credits();
int main()
{
    //setting pg_1
    pg_1[0][0] = -1;
    pg_1[1][0] = 10;  //frame no in mm
    pg_1[2][0] = -1;
    pg_1[3][0] = 13;  //frame no in mm
    pg_1[0][1] = 0;
    pg_1[1][1] = 1;
    pg_1[2][1] = 0;
    pg_1[3][1] = 1;

    //setting pg_2
    pg_2[0][0] = -1;
    pg_2[1][0] = -1;
    pg_2[2][0] = -1;
    pg_2[3][0] = 14;  //frame no in mm
    pg_2[4][0] = 16;  //frame no in mm
    pg_2[0][1] = 0;
    pg_2[1][1] = 0;
    pg_2[2][1] = 0;
    pg_2[3][1] = 1;
    pg_2[4][1] = 1;

    //setting main mem

    main_mem[mm_iter][0] = p1[1];
    mm_iter += 3;
    main_mem[mm_iter][0] = p1[3];
    mm_iter += 1;
    main_mem[mm_iter][0] = p2[3];
    mm_iter += 2;
    main_mem[mm_iter][0] = p2[4];
    mm_iter += 1;

    //setting secondary mem

    sec_mem[sm_iter][0] = p1[0];
    sm_iter += 1;
    sec_mem[sm_iter][0] = p1[1];
    sm_iter += 1;
    sec_mem[sm_iter][0] = p1[2];
    sm_iter += 1;
    sec_mem[sm_iter][0] = p1[3];
    sm_iter += 5;
    sec_mem[sm_iter][0] = p2[0];
    sm_iter += 1;
    sec_mem[sm_iter][0] = p2[1];
    sm_iter += 1;
    sec_mem[sm_iter][0] = p2[2];
    sm_iter += 1;
    sec_mem[sm_iter][0] = p2[3];
    sm_iter += 1;
    sec_mem[sm_iter][0] = p2[4];
    sm_iter += 1;

    //logical address setting

    logical_address[0][0] = 1;//p1 page no
    logical_address[0][1] = 1;//p1 offset

    logical_address[1][0] = 4;//p2 page no
    logical_address[1][1] = 1;//p2 offset

    logical_address[2][0] = 0;//p1 page no
    logical_address[2][1] = 0;//p1 offset

    logical_address[3][0] = 2;//p2 page no
    logical_address[3][1] = 1;//p2 offset

    int opt;
    while(1)
    {
        system("CLS");
        cout<<"\n\n\n\t\t\t\t\t\tMEMORY MANAGEMENT UNIT \n\n\n";
        cout<<"\nChoose One Option ";
        cout<<"\n\n\t 1.Overview \n\t 2.Working Of MMU \n\t 3.Conclusion \n\t 4.Credits \n\t 5.Exit \n\n";
        cin>>opt;
        switch(opt)
        {
            case 1 :overview();
                    break;
            case 2 :working();
                    break;
            case 3 :conclusion();
                    break;
            case 4 :credits();
                    break;
            case 5 :exit(0);
                    break;
            default :cout<<"\n Wrong Entry !!!!!! \n\n\n\t\t\t\t\tTRY AGAIN !!! \n\n\n";
        }
        cout<<"\nExit (0)  Or Main Menu (1)\n";
        cin>>opt;
        if(opt==0)
        {
            exit(0);
        }
    }
    return 0;

}

void overview()
{
    system ("CLS");

    cout<<"\n\n\t Subdividing memory to accommodate multiple processes, Memory needs to allocated efficiently to pack as many processes into memory as possible\n";

    cout<<"\n\n\n Memory Management Requirements : ";

    cout<<"\n\t 1.Relocation : Programmer does not know where the program will be placed in memory when it is executed ";
    cout<<"\n\t                While the program is executing, it may be placed in disk and returned to main memory at a different location (swapping) ";
    cout<<"\n\t                Memory references in the code (virtual or logical) must be translated to actual physical memory addresses ";

    cout<<"\n\n\t 2.Protection : Processes should not be able to reference memory locations in another process without permission. ";
    cout<<"\n\t                Impossible to check addresses in programs since the program could be relocated";
    cout<<"\n\t                Must be checked during execution";

    cout<<"\n\n\t 3.Logical Organization : Programs are written in modules ";
    cout<<"\n\t                          Different degrees of protection given to modules (read-only, execute-only) ";
    cout<<"\n\t                          Share modules - Allows us to share libraries ";

    cout<<"\n\n\t 4.Physical Organization : Memory available for a program plus its data may be insufficient ";
    cout<<"\n\t                           Secondary memory cheaper, larger capacity, and permanent";

}


void working()
{
    system ("CLS");
    cout<<"1st Process: \n"<<endl;
    cout<<"Logical address is taken and page is searched in page table\n"<<endl;
    Sleep(5000);
    if(pg_1[logical_address[0][0]][0]!=-1)
    {
        if(pg_1[logical_address[0][0]][1]!=0)
        {
            cout<<"Page has been found in main memory\n"<<endl;
            Sleep(5000);
            cout<<"Frame no is written into physical address\n"<<endl;
            physical_address[0][0] = pg_1[logical_address[0][0]][0];
        }
    }
    physical_address[0][1] = 1;
    Sleep(5000);
    cout<<"This physical address is sent to the CPU\n"<<endl;
    Sleep(8000);    //make 20000 while explaining

    cout<<"Now trying to access a page thats not present in main memory\n"<<endl;
    Sleep(5000);
    cout<<"Logical address is taken and page is searched in page table\n"<<endl;
    if(pg_1[logical_address[2][0]][0]==-1)
    {
        cout<<"Page not in main memory\n"<<endl;
        Sleep(5000);
        cout<<"Searching in secondary memory\n"<<endl;
        Sleep(5000);
        int i=0;
        while(1)
        {
            if(sec_mem[i][0]==p1[0])
            {
                cout<<"Page found in secondary memory and added to main memory\n"<<endl;
                Sleep(5000);
                main_mem[mm_iter][0] = sec_mem[i][0];
                pg_1[0][0] = mm_iter;
                mm_iter += 1;
                cout<<"Frame no is written into physical address\n"<<endl;
                Sleep(5000);
                physical_address[2][0] = pg_1[0][0];
                break;
            }
            i++;
        }
        physical_address[2][1] = 1;
        cout<<"This physical address is sent to the CPU\n"<<endl;
        Sleep(8000);
    }

    cout<<"\n2nd Process: \n"<<endl;
    cout<<"Logical address is taken and page is searched in page table\n"<<endl;
    Sleep(5000);
    if(pg_2[logical_address[1][0]][0]!=-1)
    {
        if(pg_2[logical_address[1][0]][1]!=0)
        {
            cout<<"Page has been found in main memory\n"<<endl;
            Sleep(5000);
            cout<<"Frame no is written into physical address\n"<<endl;
            physical_address[1][0] = pg_2[logical_address[1][0]][0];
        }
    }
    physical_address[1][1] = 1;
    Sleep(5000);
    cout<<"This physical address is sent to the CPU\n"<<endl;
    Sleep(8000);

    cout<<"Now trying to access a page thats not present in main memory\n"<<endl;
    Sleep(5000);
    cout<<"Logical address is taken and page is searched in page table\n"<<endl;

    if(pg_1[logical_address[3][0]][0]==-1)
    {
        cout<<"Page not in main memory\n"<<endl;
        Sleep(5000);
        cout<<"Searching in secondary memory\n"<<endl;
        int i=0;
        while(1)
        {
            if(sec_mem[i][0]==p2[2])
            {
                cout<<"Page found in secondary memory and added to main memory\n"<<endl;
                Sleep(5000);
                main_mem[mm_iter][0] = sec_mem[i][0];
                pg_2[2][0] = mm_iter;
                mm_iter += 1;
                cout<<"Frame no is written into physical address\n"<<endl;
                Sleep(5000);
                physical_address[3][0] = pg_2[2][0];
                break;
            }
            i++;
        }
        physical_address[2][1] = 1;
        cout<<"This physical address is sent to the CPU\n"<<endl;
        Sleep(8000);
    }

}

void conclusion()
{
    system ("CLS");
    cout<<"\n\n\n\t\t\t\t\tCONCLUSION ";
    cout<<"\n\n\n Memory-Management Unit (MMU) : ";
    cout<<"\n\n\n\t 1. Hardware device that maps virtual to physical address \n\t 2.In MMU scheme, the value in the relocation register is added to every address generated by a user process at the time it is sent to memory \n\t 3. The user program deals with logical addresses; it never sees the real physical addresses ";

}

void credits()
{
    system ("CLS");
    cout<<"\nDone BY : ";
    cout<<"\n\n\t Rishi S - 19PT21 \n\t Sagar - 19PT25 \n";
}
