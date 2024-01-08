#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour représenter une question
struct Question {
    char enonce[100];
    char choix1[50];
    char choix2[50];
    char choix3[50];
    char choix4[50];
    char reponseCorrecte;
    int difficulte; // Ajout de la difficulté (1 pour facile, 2 pour moyen, 3 pour difficile)
};

// Fonction pour poser une question et obtenir la réponse du joueur
char poserQuestion(struct Question *question) {
    printf("%s\n", question->enonce);
    printf("a) %s\n", question->choix1);
    printf("b) %s\n", question->choix2);
    printf("c) %s\n", question->choix3);
    printf("d) %s\n", question->choix4);

    char reponse;
    printf("Votre réponse (a, b, c, d) : ");
    scanf(" %c", &reponse);

    return reponse;
}

// Fonction pour vérifier la réponse du joueur
int verifierReponse(char reponseJoueur, struct Question *question, int *score, int *vie, int *pointsGagnes) {
    if (reponseJoueur == question->reponseCorrecte) {
        printf("Bonne réponse !\n");
        int points = (question->difficulte == 3) ? 10 : 6; // Plus de points pour les questions difficiles
        (*score) += points;
        (*pointsGagnes) += points;
        return 1; // Retourne 1 si la réponse est correcte
    } else {
        printf("Mauvaise réponse. Vous perdez une vie. La bonne réponse était : %c\n", question->reponseCorrecte);
        (*vie) -= 1;
        printf("Il vous reste %d vies.\n", *vie);
        return 0; // Retourne 0 si la réponse est incorrecte
    }
}

int main() {
    int i;
    // Initialisation des questions
    struct Question questions[16] = {
        {"Quel est le plus petit pays du monde ?", "Vatican", "Nauru", "Saint-Marin", "Maldives", 'a', 1},
        {"Quel pays a remporté la Coupe du Monde de football en 2014 ?", "Argentine", "Brésil", "Allemagne", "Italie", 'c', 2},
        {"Qui est actuellement le roi du Maroc ?", "Hassan 2", "Le Pacha de Marrakech", "Mohammed Ali", "Mohammed 6", 'd', 1},
        {"Quel est l'élément le plus abondant dans l'atmosphère terrestre ?", "Azote", "Oxygène", "Dioxyde de carbone", "Hydrogène", 'a', 3},
        {"Quel est l'animal national de l'Australie ?", "Kangourou", "Koala", "Émeu", "Dingo", 'a', 3},//
        {"Qui a écrit Le Petit Prince ?", "Victor Hugo", "Antoine de Saint-Exupéry", "Albert Camus", "Marcel Proust", 'b', 2},
        {"Quel est le plus grand océan du monde ?", "Guépard", "Lion", "Antilope", "Zèbre", 'a', 3},
        {"Quel est l'organe le plus grand du corps humain ?", "Cerveau", "Peau", "Foie", "Cœur", 'a', 3},
        {"Quel est le plus haut sommet du monde ?", "Mont Everest", "Mont Kilimandjaro", "Mont McKinley (Denali)", "Mont Fuji", 'a', 3},
        {"Quelle est la planète la plus proche du soleil ?", "Vénus", "Terre", "Mars", "Mercure", 'd', 3},
        {"Dans quelle ville se trouve la tour Eiffel ?", "monaco", "lille", "roma", "paris", 'd', 1},
        {"Quelle est la capitale de l'Espagne ?", "valence", "madrid", "barcalona", "seville", 'b', 1},
        {"quel pays gagnera la coupe du monde 2022 ?", "france", "brazil", "maroc", "argentine", 'd', 1},
        {"Qui a remporté le Ballon d'Or 2021, récompensant le meilleur joueur de football au monde ?", "neymar", "cristiano ronaldo", "lionel messi", "xavi", 'c', 2},
        {"Dans quel sport Michael Phelps a-t-il remporté le plus grand nombre de médailles olympiques?", "Athlétisme ", "Natation ", "Gymnastique ", "Tennis ", 'b', 2},
        {"Quel joueur de tennis détient le record du plus grand nombre de victoires en Grand Chelem en simple chez les hommes ?", "Rafael Nadal", "Novak Djokovic","Roger Federer", "Pete Sampras ", 'b', 2},
    };

    int score = 0;
    int vie = 3;
    int pointsGagnes = 0; // Variable pour suivre le total des points gagnés

    // Choix du niveau de difficulté
    int difficulte;
    printf("\t\tBonjour! J'espere que vous etes pris pour un test de questions pour un champion  :\n");
    printf("Choisissez le niveau de difficulté(1 pour facile, 2 pour moyen, 3 pour difficile) : ");
    scanf("%d", &difficulte);

    // Boucle de jeu
    for (i = 0; i < 16 && vie > 0 && score < 100; i++) {
        if (questions[i].difficulte == difficulte) {
            char reponseJoueur = poserQuestion(&questions[i]);
            pointsGagnes += verifierReponse(reponseJoueur, &questions[i], &score, &vie, &pointsGagnes);
        }
    }

    // Afficher le résultat du jeu
    if (score >= 100 && vie > 0) {
        printf("Félicitations, vous avez gagné !\n");
    } else {
        printf("Game over. Vous n'avez plus de vies ou n'avez pas atteint le score requis.\n");
    }

    // Afficher le total des points gagnés
    printf("Total des points gagnés : %d\n", pointsGagnes);

    return 0;
}

