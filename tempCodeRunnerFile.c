#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char nom[50];
} Client;

typedef struct {
    int idFacture;
    int idClient;
    float montant;
    float tva;
} Facture;

Client clients[MAX];
Facture factures[MAX];

int nbClients = 0;
int nbFactures = 0;

void ajouterClient() {
    printf("ID Client : ");
    scanf("%d", &clients[nbClients].id);

    printf("Nom Client : ");
    scanf("%s", clients[nbClients].nom);

    nbClients++;
    printf("Client ajoute avec succes !\n");
}

void afficherClients() {
    printf("\n--- Liste des Clients ---\n");
    for(int i = 0; i < nbClients; i++) {
        printf("ID: %d | Nom: %s\n", clients[i].id, clients[i].nom);
    }
}

int chercherClient(int id) {
    for(int i = 0; i < nbClients; i++) {
        if(clients[i].id == id) {
            return i;
        }
    }
    return -1;
}

void ajouterFacture() {

    printf("ID Facture : ");
    scanf("%d", &factures[nbFactures].idFacture);

    printf("ID Client : ");
    scanf("%d", &factures[nbFactures].idClient);

    if(chercherClient(factures[nbFactures].idClient) == -1) {
        printf("Client inexistant !\n");
        return;
    }

    printf("Montant : ");
    scanf("%f", &factures[nbFactures].montant);

    factures[nbFactures].tva = factures[nbFactures].montant * 0.19;

    nbFactures++;

    printf("Facture ajoutee avec succes !\n");
}

float calculTotal() {
    float total = 0;

    for(int i = 0; i < nbFactures; i++) {
        total += factures[i].montant;
    }

    return total;
}

int main() {

    int choix;
    int idRecherche;
    float total;

    do {

        printf("\n===== MENU =====\n");
        printf("1. Ajouter Client\n");
        printf("2. Afficher Clients\n");
        printf("3. Ajouter Facture\n");
        printf("4. Total Factures\n");
        printf("5. Chercher Client\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch(choix) {

            case 1:
                ajouterClient();
                break;

            case 2:
                afficherClients();
                break;

            case 3:
                ajouterFacture();
                break;

            case 4:
                total = calculTotal();
                printf("Total des factures : %.2f DT\n", total);
                break;

            case 5:
                printf("Entrer ID client : ");
                scanf("%d", &idRecherche);

                int pos = chercherClient(idRecherche);

                if(pos != -1)
                    printf("Client trouve : %s\n", clients[pos].nom);
                else
                    printf("Client non trouve !\n");
                break;

            case 0:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide !\n");
        }

    } while(choix != 0);

    return 0;
}
