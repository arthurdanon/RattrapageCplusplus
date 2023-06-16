#pragma once
#include "Menu.h"
#include "Concurrent.h"
#include <list>
#include <deque>
#include <map>
#include <functional>
#include <iterator>

/// <summary>
/// La classe Application est celle qui contient tout le fonctionnement du programme
/// </summary>
class Application
{
private:
	/// <summary>
	/// Le menu de l'application
	/// </summary>
	Menu menu;

	/// <summary>
	/// 
	/// @TODO D�clarer les 3 conteneurs avec les noms et caract�ristiques indiqu�s dans le sujet
	std::deque<int> dossardsPourAffectation; // conteneur pour les dossards disponibles
	std::list<Concurrent> concurentsInscrits; // conteneur pour les concurrents inscrits
	std::multimap<int, Concurrent> resultats; // conteneur pour les concurrents notés avec leur score
	/// 
	/// </summary>



public:
	/// <summary>
	/// Initialiser la comp�tition.
	/// Consiste � saisir le nombre de dossards n�cessaires (= nombre de concurrents)
	/// puis � les cr�er dans le conteneur dossardsPourAffectation.
	/// Entre 2 et 100 dossards.
	void InitialiserCompetition();
	void InscrireUnConcurrent();
	void AfficherParNom();
	void AfficherParDossard();
	void NoterConcurrents();
	void AfficherResultats();
	void Run();
	/// </summary>
	void InitialiserCompetition();

	/// <summary>
	/// Inscrire un concurent.
	/// Apr�s v�rification qu'il reste un dossard disponible, il faut:
	/// - saisir le nom du concurrent
	/// - retirer 1 dossard au hasard dans le conteneur dossardsPourAffectation
	/// - cr�er le concurrent avec son nom et le dossard
	/// - ajouter le concurrent au conteneur concurentsInscrits
	/// Pas d'inscription possible s'il ne reste plus de dossard disponible.
	/// Le concurrent est affich� ainsi que le nombre de dossards pouvant encore �tre attribu�s.
	/// </summary>
	{
	int nombreConcurrents;
	do {
		cout << "Entrez le nombre de concurrents (entre 2 et 100): ";
		cin >> nombreConcurrents;
	} while (nombreConcurrents < 2 || nombreConcurrents > 100);

	for(int i = 0; i < nombreConcurrents; i++) {
		dossardsPourAffectation.push_back(i+1);
	}
}
	void InscrireUnConcurrent();

	/// <summary>
	/// Affiche la liste des concurrents inscrits par ordre alphab�tique des noms
	/// </summary>
	void AfficherParNom();

	/// <summary>
	/// Affiche la liste des concurrents inscrits par ordre croissant des dossards
	/// </summary>
	void AfficherParDossard();

	/// <summary>
	/// Permet de noter (scorer) tous les concurrents.
	/// - extrait et supprime le premier concurrent du conteneur concurentsInscrits
	/// - lui affecte un score entre 0 et 10 inclus
	/// - ins�re le concurrent not� dans le conteneur resultats, les mieux not�s rang�s en premier
	/// Le score doit servir de cl� pour retrouver tous les concurrents ayant un certain score.
	/// Attention!! On peut avoir plusieurs concurrents avec le m�me score.
	/// </summary>
	void NoterConcurrents();

	/// <summary>
	/// Affiche le score, le dossard et le nom des concurrents not�s.
	/// </summary>
	void AfficherResultats();

	/// <summary>
	/// Boucle d'ex�cution du programme.
	/// </summary>
	void Run();
};

