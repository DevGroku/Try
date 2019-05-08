#include <iostream>

int main()
{
    int a = 5; // variable : sur la pile(stack), de type int, de valeur 5
    int* p = &a; // variable : sur la pile, de type int* (pointeur sur int), de valeur &a (adresse de a)

    std::cout << "valeur de a : " << a << std::endl;
    std::cout << "adresse de a : " << &a << std::endl;
    std::cout << "valeur de p : " << p << std::endl;
    std::cout << "valeur contenue a l'adresse de p : " << *p << std::endl;



    std::cout << std::endl;



    int* b = new int{ 9 }; // variable : sur le tas (heap), de type int*, de valeur [adresse retournée par new] pointant sur un int de valeur 5
    std::cout << "valeur de b : " << b << std::endl;
    std::cout << "valeur a l'adresse de b : " << *b << std::endl;



    std::cout << std::endl;



    // {} : un scope
    // on est dans le scope de la fonction main()
    std::string* pointeur_sur_c = nullptr; // nullptr : pointeur nul, ne pointe sur rien, déclaré dans le scope de main()
    { // debut de scope
      std::string c = "static salut"; // déclaré dans un nouveau scope
      pointeur_sur_c = &c;

      std::cout << "valeur de pointeur_sur_c : " << pointeur_sur_c << std::endl;
      std::cout << "valeur de c : " << *pointeur_sur_c << std::endl;
    } // fin de scope (les variables sur la pile déclarées dans ce scope sont détruites) c est détruit


    std::cout << "valeur de pointeur_sur_c : " << pointeur_sur_c << std::endl; // pointeur_sur_c valide dans ce scope
    std::cout << "valeur de c (UB) : " << /*pointeur_sur_c <<*/ std::endl; // crash, UB (undefined behaviour) on récupère la valeur de c qui a été détruit



    std::cout << std::endl;



    // on est dans le scope de la fonction main()
    std::string* pointeur_a = nullptr; // nullptr : pointeur nul, ne pointe sur rien, déclaré dans le scope de main()
    { // debut de scope
        std::string* d = new std::string{ "dynamic salut" }; // déclaré dans un nouveau scope
        pointeur_a = d;

        std::cout << "valeur de d : " << d << std::endl;
        std::cout << "valeur de pointeur_a : " << pointeur_a << std::endl;
        std::cout << "valeur a l'adresse de d : " << *d << std::endl;
    } // fin de scope, la variable d est détruite(le pointeur), la valeur à l'adresse de d n'est pas détruite (il existe une valeur std::string quelquepart, on connait l'adresse grace à pointeur_a

    // std::cout << "valeur de d : " << d << std::endl; // erreur de compilation d n'est pas déclaré dans le scope de main()
    std::cout << "valeur de pointeur_a : " << pointeur_a << std::endl;
    std::cout << "valeur a l'adresse de pointeur_a : " << *pointeur_a << std::endl;

    std::cout << "delete de la valeur a l'adresse pointeur_a" << std::endl;
    delete pointeur_a; // on détruit la valeur à l'adresse pointeur_a
    /*delete pointeur_a;*/ // deja delete, crash

    std::cout << "valeur de pointeur_a : " << pointeur_a << std::endl; // le pointeur a la meme valeur (meme adresse mais la valeur n'existe plus)
    std::cout << "valeur de d (UB) : " << /*pointeur_a <<*/ std::endl; // la valeur n'existe plus (UB)

    pointeur_a = nullptr; // après un delete, on met le pointeur à nullptr pour dire qu'il pointe sur rien
    std::cout << "valeur de pointeur_a : " << pointeur_a << std::endl;

    delete pointeur_a; // ok

    return 0;
}