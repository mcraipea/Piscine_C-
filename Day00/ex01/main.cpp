#include "annuaire.h"

using namespace std;

static int		ft_add(Contact contact_tab[8])
{
	int			i(0);
	string      infos_name[11] = { "first name", "last name", "nickname", "login", "postal adress", "email adress", "phone number", "birthday date", "favorite meal", "underwear color", "darkest secret"};
	Contact		new_contact;

	while (!contact_tab[i].infos[0][0].empty() && i < 8)
		i++;
	if (i == 8)
		return (1);
	for (int j = 0; j < 11; j++)
	{
		new_contact.infos[j][0] = infos_name[j];
		cout << new_contact.infos[j][0] << " : ";
		getline(cin, new_contact.infos[j][1]);
	}
	contact_tab[i] = new_contact;
	return (0);
}

static void		ft_resize(string s)
{
	if (s.size() > 10)
	{
		s = s.insert(9, ".");
		s = s.substr(0, 10);
	}
	else
	{
		while (s.size() < 10)
			s = s.insert(0, " ");
	}
	cout << s;
}

static int		ft_affich(Contact contact_tab[8])
{
	int		i(0);
	while (!contact_tab[i].infos[0][1].empty() && i < 7)
	{
		cout << "         " << i + 1 << "|";
		ft_resize(contact_tab[i].infos[0][1]);
		cout << "|";
		ft_resize(contact_tab[i].infos[1][1]);
		cout << "|";
		ft_resize(contact_tab[i].infos[2][1]);
		cout << endl;
		i++;
	}
	return (i - 1);
}

static void		ft_search(Contact contact_tab[8])
{
	int		i(0);
	int		rep(0);
	int		total(0);

	total = ft_affich(contact_tab) + 1;
	cout << "Quel numero de contact souhaitez vous voir ?  ";
	cin >> rep;
	if (rep < 1)
	{
		cout << "Surement une faute de frappe..." << endl;
		return ;
	}
	else if (rep > total)
	{
		cout << "Vous n'avez pas autant d'ami voyons ! ;)" << endl;
		return ;
	}
	else
	{
		while (i < 11)
			cout << contact_tab[rep - 1].infos[i++][1] << endl;
	}
}

int 			main()
{
    string     rep;
    Contact    contact_tab[8];

	cout << "Bienvenue dans votre annuaire interractif :" << endl;
    cout << "Quel est votre choix?" << endl;
    cout << "- ADD : ajoutez un contact" << endl;
    cout << "- SEARCH : cherchez un contact" << endl;
    cout << "- EXIT" << endl;
    while (rep != "EXIT")
    {
        getline(cin, rep);
        if (rep == "ADD")
        {   
			if (ft_add(contact_tab))
				cout << "Votre liste est pleine... Passez au minitel 2.0" << endl;
			cout << "nouveau choix : ADD, SEARCH, ou EXIT." << endl;
		}
        else if (rep == "SEARCH")
        {
		    ft_search(contact_tab);
			cout << "nouveau choix : ADD, SEARCH, ou EXIT." << endl;
		}
	}
	cout << "A bientot !" << endl;
    return (0);
}