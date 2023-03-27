#include<stdio.h>
#include<time.h>
#include<string.h>

//Sasanka Deshapriya

struct members{
    int ID;
    char courtesy[4];
    char fname[20];
    char lname[20];
    char gender[8];
    char acctype[10];
    int voted;
    int votescount;
};

void dm(); void vm(); void finalresult();
struct members m[15];
int voteapplicant1=0,voteapplicant2=0, voteapplicant3=0, voteapplicant4=0, voteapplicant5=0, votespoiled=0;

int main(){

    char user; int choice;
    time_t t = time(NULL); struct tm tm = *localtime(&t);
    printf("\tICT club presidential election: %d\n\n",tm.tm_year + 1900);

	do{
	printf("\n\tDeveloper Mode [1]\tVoter Mode [2]\tResult [3]\t\n\tList of Eligible Voters [4]\tList of Candidate [5]\tExit [0]\n");
	printf("\n\tEnter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            dm();
            break;
        case 2:
            vm();
            break;
        case 3:
            finalresult();
            break;
        case 4:
            printf("\n\tEligible Voters Data: Registration NO, First Name\n\n");
            for (int e=0;e<15;e++){
                if(strcmp(m[e].acctype,"Voter")== 0){
                    printf("\t%d \t%s\n",m[e].ID,m[e].fname);
                }
            }
            printf("\t\n");
            break;
        case 5:
            printf("\n\tCandidates Data: Registration NO, First Name\n\n");
            for (int e=0;e<15;e++){
                if(strcmp(m[e].acctype,"Candidate")== 0){
                    printf("\t%d \t%s\n",m[e].ID,m[e].fname);
                }
            }
            printf("\t\n");
            break;
        default:
            printf("\n\tError: Invalid Choice\n\n");
    	}
	}while(choice!=0);
	//for hold the screen
    getchar();
    return 0;
}

void dm(){
    int odm,rnum;
    printf("\n\tDeveloper Mode\n\n");
    do{
        printf("\n\tOperations: \n\tTo Enter Membership Data[1]\tTo Define Members As presidential Applicants[2]\t\tTo view Data Table[3]\n\tMain Menu[0]\n\n");
        printf("\tWhich operation do you want to do?(Please Enter Operation Number): ");
        scanf("%d",&odm);
        switch(odm){
            case 1:
                printf("\n\tEnter members' data\n\n");
                for(int x=0; x<15;x++){
                    printf("\tData related to Registration No.%d \n",x);
                    m[x].ID = x;
                    m[x].voted = 0;
                    printf("\tEnter Courtesy(Mr/Miss/Mrs): ");
                    scanf("%s",m[x].courtesy);
                    printf("\tEnter First Name: ");
                    scanf("%s",m[x].fname);
                    printf("\tEnter Last Name: ");
                    scanf("%s",m[x].lname);
                    printf("\tEnter Gender: ");
                    scanf("%s",m[x].gender);
                    strcpy(m[x].acctype, "Voter");
                    printf("\n//Successfully added\n\n");
                }
                break;
            case 2:
                printf("\n\tTo Define Member As presidential Applicant: Enter Registration No. Only five members can be nominated.\n\n");
                int y=1;
                while(y<=5){
                    printf("\tEnter Member Registration No: ");
                    scanf("%d",&rnum);
                    if(rnum>=0&&rnum<=14){
                        strcpy(m[rnum].acctype, "Candidate");
                        y++;
                    }else{
                        printf("\tInvalid Registration NO\n");
                    }
                }
                break;
            case 3:
                printf("\n\tMembers Data: Registration NO, Courtesy, First Name, Last Name, Gender, Account Type\n\n");
                for (int z=0;z<15;z++){
                    printf("\t%d \t %s \t %s \t %s \t %s \t %s\n",m[z].ID,m[z].courtesy,m[z].fname,m[z].lname,m[z].gender,m[z].acctype);
                }
                break;
            default:
                printf("\n\tInvalid Operation\n\n");
        }
    }while(odm!=0);
    getchar();
}

void vm(){
    int ovm,rn,chv,eq,xyz=0,n;
    printf("\n\tVoter Mode\n\n");
    do{
        printf("\n\tOperations: \n\tCast the Vote[1]\tMain Menu[0]\n\n");
        printf("\tWhich operation do you want to do?(Please Enter Operation Number): ");
        scanf("%d",&ovm);

        switch(ovm){
        case 1:
            do{
                printf("\n\tIf the registration number is incorrect, nothing will be displayed | GO Back[16]\n\tEnter your member ID(Reg NO): ");
                scanf("%d",&rn);
                for(int n=0;n<15;n++){
                    if(rn == m[n].ID && strcmp(m[n].acctype,"Voter")== 0 && m[n].voted == 0){
                        m[n].voted = 1;
                        printf("\n\t\n");
                        printf("\n\tList of Presidential Applicants\n\n");
                        printf("\tNum \tName\n\n");
                        xyz = 0;
                        for (int e=0;e<15;e++){
                            if(strcmp(m[e].acctype,"Candidate")== 0){
                            printf("\t%d \t%s\n",xyz,m[e].fname);
                            eq = e;
                            xyz++;
                            }
                        }
                        printf("\t\n");
                        printf("\t%s %s you can vote 3 times. During the 3 time the you can select same person if you  want.",m[eq].courtesy,m[eq].lname);
                        for(int cc=0;cc<3;cc++){
                            printf("\n\tInput your %d choice (0-4) Spoiled Votes (5): ",cc+1);
                            scanf("%d",&chv);
                            switch(chv){
                                case 0:
                                    voteapplicant1++;
                                    m[0].votescount = voteapplicant1;
                                    break;
                                case 1:
                                    voteapplicant2++;
                                    m[1].votescount = voteapplicant2;
                                    break;
                                case 2:
                                    voteapplicant3++;
                                    m[2].votescount = voteapplicant3;
                                    break;
                                case 3:
                                    voteapplicant4++;
                                    m[3].votescount = voteapplicant4;
                                    break;
                                case 4:
                                    voteapplicant5++;
                                    m[4].votescount = voteapplicant5;
                                    break;
                                case 5:
                                    votespoiled++;
                                    break;
                                default:
                                    printf("\n\tError: Wrong Choice !! Please retry");
                                    --cc;
                            }
                        }
                    }
                }
            }while(rn!=16);
            break;
        default:
            printf("\n\tInvalid Operation\n\n");
        }

    }while(ovm!=0);
    getchar();
}

int ccccc = 0;

void finalresult(){
    printf("\n\n\t---------------------------------------------- Voting Results --------------------------------------------------\n\n");

    for (int ccc=0;ccc<15;ccc++){
        if(strcmp(m[ccc].acctype,"Candidate")== 0){
            printf("\tCANDIDATE ID: %d  Member ID: %d  Name: %s = %d Votes\n",ccccc,m[ccc].ID,m[ccc].fname,m[ccccc].votescount);
            ccccc++;
        }
    }
    printf("\n\t%s : %d ", "Spoiled Votes", votespoiled);
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    if(voteapplicant1>voteapplicant2 && voteapplicant1>voteapplicant3 && voteapplicant1>voteapplicant4 && voteapplicant1>voteapplicant5){
        printf("\n\tThe selected president for the year  Applicant 0\n");
    }else if(voteapplicant2>voteapplicant1 && voteapplicant2>voteapplicant3 && voteapplicant2>voteapplicant4 && voteapplicant2>voteapplicant5){
        printf("\n\tThe selected president for the year  Applicant 1\n");
    }else if(voteapplicant3>voteapplicant1 && voteapplicant3>voteapplicant2 && voteapplicant3>voteapplicant4 && voteapplicant3>voteapplicant5){
        printf("\n\tThe selected president for the year  Applicant 2\n");
    }else if(voteapplicant4>voteapplicant1 && voteapplicant4>voteapplicant2 && voteapplicant4>voteapplicant3 && voteapplicant4>voteapplicant5){
        printf("\n\tThe selected president for the year  Applicant 3\n");
    }else if(voteapplicant5>voteapplicant1 && voteapplicant5>voteapplicant2 && voteapplicant5>voteapplicant3 && voteapplicant5>voteapplicant4){
        printf("\n\tThe selected president for the year  Applicant 4\n");
    }else{
        printf("\n\n\tSorry!! No win situation!\n");
    }
    ccccc = 0;
}
