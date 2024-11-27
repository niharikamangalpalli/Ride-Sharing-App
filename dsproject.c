#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RESET "\x1b[0m"
#define RED   "\x1b[31m"
#define BLUE   "\x1b[34m"
#define YELLOW  "\x1b[33m"
#define GREEN   "\x1b[32m"
#define CYAN    "\x1b[36m"
#define MAGENTA "\x1b[35m"

#define BOLD "\x1b[1m"
#define UNDERLINE "\x1b[4m"
#define ITALIC "\x1b[3m"

#define MAX_STOP_NAME_LEN 100

typedef struct cname {
    char* loc;
    struct cname* next;
    struct cname* prev;
} cname;

typedef struct Node {
    char arr[MAX_STOP_NAME_LEN];
    struct Node *next;
} node;

const char *locationNames[] = {
    "Parvati Hill Station",
    "Aga Khan Palace",
    "Fashion Street Deccan",
    "Science Park",
    "Shaniwarwada",
    "Alandi"};

void store(int allroute[6][6]);
void pune(int allroute[6][6],cname*** track);
void prims(int n, int distance[6][6], int userlocs[6],cname*** track);
cname* createsll(cname* head, const char* arr);
cname* mergesll(cname* h1, cname* h2);
cname* reversesll(cname* h1);
char* compare(cname* h1, cname* h2);
void display(cname* h);
node* createNode(const char* location);
void displayLocations(node* head);
void freeLinkedList(cname* head);

int main(void) {
    int place, ch;
    int allroute[6][6];
    printf(BOLD UNDERLINE RED "\n\t\t\t\t**WELCOME TO JOURNEY-JOY <3\n"RESET);
    printf(MAGENTA BOLD"\n\n\t\t^_^"RESET);
    printf(CYAN"\tEXPLORE YOUR FAVORITE CITY WITH US\t"RESET);
    printf(MAGENTA BOLD"^_^"RESET);
    printf(CYAN ITALIC"\n\tTravel less and explore more!! Save time and the hazard of searching new places to visit\n"RESET);
    printf(CYAN ITALIC"Whether it's your first time in the city or you're looking to rediscover its hidden gems, we've got you covered!\n"RESET);
    printf(CYAN ITALIC"\tLet JOURNEY-JOY guide you through the best spots to explore & make the most of your moment!\n\n\n"RESET);

    printf(RED"~To immerse in the Vibrance of HERITAGE and YOUTH: PUNE ;)-->ENTER 1\n"RESET);
    /printf(BLUE"~To embrace the Spirit of HUSTLE and HARMONY: MUMBAI ;)-->ENTER 2\n"RESET);/
    scanf("%d", &place);
    store(allroute);
 cname** track = (cname*)malloc(sizeof(cname*) * 6);
    for (int i = 0; i < 6; i++) {
        track[i] = (cname*)malloc(sizeof(cname) * 6);
    }

    // Initialize track routes for Pune
    track[0][1] = NULL;
    track[0][1] = createsll(track[0][1], "laxminagar");
    track[0][1] = createsll(track[0][1], "yerwada");
    track[0][1] = createsll(track[0][1], "ramwadi");
    track[0][1]=createsll(track[0][1],"NULL");
    track[0][2] = NULL;
    track[0][2] = createsll(track[0][2], "laxminagarpolicechowky");
    track[0][2] = createsll(track[0][2], "swargatebusstand");
    track[0][2] = createsll(track[0][2], "junaphulgate");
track[0][2]=createsll(track[0][2],"NULL");
    track[0][3] = NULL;
    track[0][3] = createsll(track[0][3], "laxminagarpolicechowky");
    track[0][3] = createsll(track[0][3], "swargate");
    track[0][3] = createsll(track[0][3], "PCMC");
track[0][3]=createsll(track[0][3],"NULL");
    track[0][4] = NULL;
    track[0][4] = createsll(track[0][4], "laxminagar");
    track[0][4] = createsll(track[0][4], "bajiraoroad");
track[0][4]=createsll(track[0][4],"NULL");
    track[0][5] = NULL;
    track[0][5] = createsll(track[0][5], "mitramandalchowk");
    track[0][5] = createsll(track[0][5], "shankarroad");
    track[0][5] = createsll(track[0][5], "sambhajichowk");
track[0][5]=createsll(track[0][5],"NULL");

    track[1][0] = NULL;
    track[1][0] = reversesll(track[1][0]);
track[1][0]=createsll(track[1][0],"NULL");

    track[1][2] = NULL;
    track[1][2] = createsll(track[1][2], "agakhanpalace");
    track[1][2] = createsll(track[1][2], "westend");
track[1][2]=createsll(track[1][2],"NULL");

    track[1][3] = NULL;
    track[1][3] = createsll(track[1][3], "agakhanpalace");
    track[1][3] = createsll(track[1][3], "chinchwadstation");
track[1][3]=createsll(track[1][3],"NULL");

    track[1][4] = NULL;
    track[1][4] = createsll(track[1][4], "agakhanpalace");
    track[1][4] = createsll(track[1][4], "manapanadikinari");
track[1][4]=createsll(track[1][4],"NULL");

    track[1][5] = NULL;
    track[1][5] = createsll(track[1][5], "agakhanpalace");
    track[1][5] = createsll(track[1][5], "sambhajichowk");
track[1][5]=createsll(track[1][5],"NULL");

    track[2][0] = NULL;
    track[2][0] = reversesll(track[0][2]);
    track[2][0]=createsll(track[2][0],"NULL");

    track[2][1]=reversesll(track[1][2]);
    track[1][0]=createsll(track[0][4],"NULL");

    track[2][3]=NULL;
    track[2][3]=createsll(track[2][3], "pune railway station");
    track[2][3]=createsll(track[2][3],"Chinchwad Junction");
 track[2][3]=createsll(track[2][3],"NULL");
    track[2][4]=NULL;
    track[2][4]=createsll(track[2][4], "Westend");
    track[2][4]=createsll(track[2][4], "Shaniwar wada stand");
 track[2][4]=createsll(track[2][4],"NULL");
    track[2][5]=NULL;
    track[2][5]=createsll(track[2][5], "MG Road Pune camp");
    track[2][5]=createsll(track[2][5], "G.P.O");
    track[2][5]=createsll(track[2][5], "Bhosari Pmt Chowk");
    track[2][5]=createsll(track[2][5], "Sambhaji CHowk");
 track[2][5]=createsll(track[2][5],"NULL");
    track[3][0]=NULL;
    track[3][0]=reversesll(track[0][3]);
 track[3][0]=createsll(track[3][0],"NULL");
    track[3][1]=NULL;
    track[3][1]=reversesll(track[1][3]);
 track[3][1]=createsll(track[3][1],"NULL");
    track[3][2]=NULL;
     track[3][2]=reversesll(track[2][3]);
 track[3][2]=createsll(track[3][2],"NULL");
     track[3][4]=NULL;
     track[3][4]=createsll(track[3][4],"Pune Vidyapeeth chowk");
     track[3][4]=createsll(track[3][4],"Ma Na Pa Congress Bhavan");
 track[3][4]=createsll(track[3][4],"NULL");
     track[3][5]=NULL;
     track[3][5]=createsll(track[3][5],"Empire Estate");
     track[3][5]=createsll(track[3][5],"HA COmpany");
     track[3][5]=createsll(track[3][5],"Y.C.M(Sant Tukaram Nagar)");
     track[3][5]=createsll(track[3][5],"Sambhaji Chowk");
 track[3][5]=createsll(track[3][5],"NULL");
track[4][0]=NULL;
track[4][0]=reversesll(track[0][4]);
 track[4][0]=createsll(track[4][0],"NULL");
track[4][1]=NULL;
track[4][1]=reversesll(track[1][4]);
 track[4][1]=createsll(track[4][1],"NULL");
track[4][2]=NULL;
track[4][2]=reversesll(track[2][4]);
 track[4][2]=createsll(track[4][2],"NULL");
track[4][3]=NULL;
track[4][3]=reversesll(track[3][4]);
 track[4][3]=createsll(track[4][3],"NULL");
track[4][5]=NULL;
track[4][5]=createsll(track[4][5],"Ma Na Pa Dhengle Pul Nandikhathi");
track[4][5]=createsll(track[4][5],"Sasoon Hospital");
track[4][5]=createsll(track[4][5],"Sambhaji Chowk");
 track[4][5]=createsll(track[4][5],"NULL");
track[5][0]=NULL;
track[5][0]=reversesll(track[0][5]);
 track[5][0]=createsll(track[5][0],"NULL");
track[5][1]=NULL;
track[5][1]=reversesll(track[1][5]);
 track[5][1]=createsll(track[5][1],"NULL");
track[5][2]=NULL;
track[5][2]=reversesll(track[2][5]);
 track[5][2]=createsll(track[5][2],"NULL");
track[5][3]=NULL;
track[5][3]=reversesll(track[3][5]);
 track[5][3]=createsll(track[5][3],"NULL");
track[5][4]=NULL;
track[5][4]=reversesll(track[4][5]);
 track[5][4]=createsll(track[5][4],"NULL");
    if (place == 1) {
        pune(allroute,track);
    } /*else if (place == 2) {
        printf(RED BOLD"SORRY, OUR MUMBAI DATABASE IS STILL IN PROGESS :(\nWE WILL UPDATE IT SOON!!\nTHANK YOU <3 "RESET);//Mumbai in progress
    } */else {
        printf(RED BOLD"SORRY, YOU'VE TRIED ENTERED AN OPTION THAT'S NOT ON THE LIST :(\n"RESET);
    }
    printf(GREEN"\nENTER 1 if you want to check if any other user is travelling on the same route\n"RESET);
    printf(GREEN"\nENTER 0 to exit :)\n"RESET);
    scanf("%d", &ch);
long long int phoneNumber;
if (ch == 1) {
    printf(MAGENTA"Travel details to be entered by another user!!\n" RESET);
    pune(allroute, track);
    printf(GREEN "Enter your phone number:" RESET);
    scanf("%lld", &phoneNumber);
    printf(GREEN "You can contact User 2 for easy travel: %lld\n" RESET, phoneNumber);
    printf("If you find any common place on the route, do contact the other user to save time, money and make new friends >_<");
} else {
    printf(YELLOW "Sadly :( No one is going from your route\n" RESET);
}

    return 0;
}

void store(int allroute[6][6]) {
    int temp[6][6] = {
        {0, 15, 6, 21, 4, 20},
        {15, 0, 6, 18, 9, 17},
        {6, 6, 0, 19, 4, 26},
        {21, 18, 19, 0, 17, 15},
        {4, 9, 4, 17, 0, 22},
        {20, 17, 26, 15, 22, 0}
    };

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            allroute[i][j] = temp[i][j];
        }
    }
}

void pune(int allroute[6][6],cname*** track) {
    int n;
    printf(MAGENTA"\nLOCATIONS TO EXPLORE:~\n"RESET);
    printf("1.Parvati Hill Station\n 2.Aga Khan Palace\n 3.Fashion Street Deccan\n 4.Science Park\n 5.Shaniwarwada\n 6.Alandi\n\n");
    printf(YELLOW"How many places are you curious to explore amongst these?! >_<\n"RESET);
    scanf("%d", &n);

    int userLocs[n];
    for (int i = 0; i < n; i++) {
        printf(BLUE"Enter location ID for the place you want to visit %d:" RESET, i + 1);
        scanf("%d", &userLocs[i]);
    }

    int distance[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            distance[i][j] = allroute[userLocs[i] - 1][userLocs[j] - 1];
        }
    }

    // Print the distance matrix
    printf("\nDistance Matrix for selected locations:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", distance[i][j]);
        }
        printf("\n");
    }

    // Run Prim's Algorithm to determine the MST
    prims(n, distance, userLocs,track);
}

void prims(int n, int distance[6][6], int userlocs[6] , cname*** track) {
    int selected[n];
    int noOfEdges = 0;
    int totalWeight = 0;

    // Arrays to store route details
    int routeStart[n - 1], routeEnd[n - 1], routeDistance[n - 1];

    // Initialize all nodes as unselected
    for (int i = 0; i < n; i++) {
        selected[i] = 0;
    }

    // Start with the first node
    selected[0] = 1;

    printf(RED"\nTHE BEST ROUTE FOR YOU IS: :)\n"RESET);

    while (noOfEdges < n - 1) {
        int min = 9999;
        int x = 0, y = 0;

        // Find the smallest edge
        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && distance[i][j]) 
                    {
                        if(min>distance[i][j])
                        {
                         min = distance[i][j];
                        x = i;
                        y = j;
                        }  
                    }
                }
            }
        }
   // printf("%d\n", x+2);
     //   printf("%d\n", y+2);
        // Store the route details
        routeStart[noOfEdges] = x;
        routeEnd[noOfEdges] = y;
        routeDistance[noOfEdges] = min;
        

        printf("Route %d: (%s -> %s) - Distance: %d KM\n", noOfEdges + 1,
               locationNames[userlocs[x] - 1], locationNames[userlocs[y] - 1], min);
        printf("\nDetailed Travel Route:\n");
     if (track[userlocs[x] - 1][userlocs[y] - 1] != NULL) {
    display(track[userlocs[x] - 1][userlocs[y] - 1]);
} else {
    printf("No route found for this pair.\n");
}
        totalWeight += min;
        selected[y] = 1;
        noOfEdges++;
    }

    // Display the MST routes
}

cname* createsll(cname* head, const char* arr) {
    cname* temp = (cname*)malloc(sizeof(cname));
    temp->loc = (char*)malloc(strlen(arr) + 1);
    strcpy(temp->loc, arr);
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        cname* temp2 = head;
        while (temp2->next!= NULL) {
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp->prev = temp2;
    }
    return head;
}

cname* mergesll(cname* h1, cname* h2) {
    cname* temp = h1;
    if (h1 == NULL) {
        return h2;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = h2;
    return h1;
}

cname* reversesll(cname* head) {
    cname* temp = NULL;
    cname* current = head;
    while (current != NULL) {
        temp = current;
        current = current->next;
    }
    return temp;
}

char* compare(cname* h1, cname* h2) {
    while (h1 != NULL && h2 != NULL) {
        if (strcmp(h1->loc, h2->loc) == 0) {
            return h1->loc;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return "No common locations.";
}

void freeLinkedList(cname* head) {
    cname* current = head;
    cname* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current->loc);
        free(current);
        current = nextNode;
    }
}

node* createNode(const char* location) {
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->arr, location);
    newNode->next = NULL;
    return newNode;
}

void displayLocations(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%s\n", current->arr);
        current = current->next;
    }
}
void display(cname* head) {
    cname* current = head;
    if (current == NULL) {
        printf(BLUE" SADLY :( No travel routes are available.\n"RESET);
        return;
    }
    while (current != NULL) {
        printf("-> %s ", current->loc);
        current = current->next;
    }
    printf("\n");
}
