

#include <iostream>
#include <string>
using namespace std;

// class that handles hero customization and profile creation.
class Hero
{
private:
    string name;
    string heroType;
    int maxHealth;

public:
    bool hasKey = false;
    bool hasShield = false;

    // Accessors for the Hero class attributes.
    string getName() const { return name; }
    string getHeroType() const { return heroType; }
    int getMaxHealth() const { return maxHealth; }

    // Mutators for the Hero class attributes.
    void setName(string heroName) { name = heroName; }
    void setHeroType(string type) { heroType = type; }
    void setMaxHealth(int hp) { maxHealth = hp; }

    // Display function that prints the hero's profile information.
    void displayProfile()
    {
        cout << "HERO PROFILE CREATED" << endl;
        cout << "-------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Role: " << heroType << endl;
        cout << "Max Health: " << maxHealth << endl;
        cout << "-------------------" << endl;
    }
};

int main()
{
    Hero player;
    string command;

    cout << "====================================" << endl;
    cout << "       THE SECRETS OF BRIMSTONE     " << endl;
    cout << "====================================" << endl;

    // Game Backstory Introduction
    cout << "Deep down the ruins of Brimstone Keep lies a legendary vault." << endl;
    cout << "Your objective is simple: navigate the dangers, bypass the security, and retrieve the priceless Gold Skull." << endl;
    cout << "But beware, the vault is protected by ancient traps and mystical guardians." << endl;
    cout << "Your journey begins now..." << endl;

    // ------------------------------------------------------------
    // HERO CREATION PHASE
    // ------------------------------------------------------------
    // Prompt the player to create their hero profile.
    cout << "Let's start by creating your hero profile." << endl;
    cout << "Enter your hero's name: ";
    getline(cin, command);
    player.setName(command);

    // Prompt the player to choose their hero type and set attributes accordingly.
    cout << "Choose your role (Tank, Mage, Marksman, Fighter or Jungler): ";
    getline(cin, command);
    player.setHeroType(command);

    // Set hero attributes based on the chosen role.
    if (command == "Tank")
    {
        player.setHeroType("Tank");
        player.setMaxHealth(200);
        cout << "You chose the Tank! Unstoppable defense and massive health. Prepare to absorb the hits!" << endl;
    }
    else if (command == "Mage")
    {
        player.setHeroType("Mage");
        player.setMaxHealth(90);
        cout << "You chose the Mage! Master of arcane arts and devastating spells. Harness the power of the elements!" << endl;
    }
    else if (command == "Marksman")
    {
        player.setHeroType("Marksman");
        player.setMaxHealth(100);
        cout << "You chose the Marksman! Precision and speed are your greatest assets. Pick off enemies from a distance!" << endl;
    }
    else if (command == "Fighter")
    {
        player.setHeroType("Fighter");
        player.setMaxHealth(140);
        cout << "You chose the Fighter! Balanced between offense and defense. A versatile warrior ready for any challenge!" << endl;
    }
    else if (command == "Jungler")
    {
        player.setHeroType("Jungler");
        player.setMaxHealth(120);
        cout << "You chose the Jungler! Agile and cunning, navigate the shadows and strike when the moment is right!" << endl;
    }
    else
    {
        player.setHeroType("Adventure");
        player.setMaxHealth(110);
        cout << "You chose a balanced Adventure path!" << endl;
    }

    // Output the hero's profile information.
    player.displayProfile();
    cout << "Your journey begins now, " << player.getName() << " the " << player.getHeroType() << "!" << endl;

    // Main game Loop for full-game failures and resets.
    bool running = true;
    while (running == true)
    {
        // Reset everything at the start of each run.
        int health = player.getMaxHealth();
        player.hasKey = false;
        player.hasShield = false;
        bool alive = true;

        // Decision 1: The Entrance Crossroad (Item Pickup)
        cout << endl << "STAGE 1: THE ENTRANCE CROSSROAD" << endl;
        cout << "You stand at a crossroad. You see a shining key on the ground. Do you pick it up? (yes/no): ";
        getline(cin, command);
        if (command == "yes")
        {
            player.hasKey = true;
            cout << "You picked up the key! This might be useful later." << endl;
        }
        else
        {
            cout << "You decided to leave the key." << endl;
        }

        // Decision 2: The Armory (Item Pickup)
        cout << endl
             << "STAGE 2: THE ARMORY" << endl;
        cout << "A dusty armory lies ahead. A sturdy shield hangs on the wall. Do you take the shield? (yes/no): ";
        getline(cin, command);
        if (command == "yes")
        {
            player.hasShield = true;
            cout << "You took the shield! This will help you defend against attacks." << endl;
        }
        else
        {
            cout << "You decided to leave the shield." << endl;
        }

        // Decision 3: The Trapped Corridor (Damage depends on shield)
        cout << endl
             << "STAGE 3: THE TRAPPED CORRIDOR" << endl;
        cout << "Spikes shoot out from the walls!" << endl;
        // Check if the player has a shield to absorb damage.
        if (player.hasShield == true)
        {
            cout << "Your shield absorbs the damage! You take no damage." << endl;
        }
        else
        {
            // Player takes damage if they don't have a shield.
            health = health - 50;
            cout << "Without a shield, you take 50 damage! Health: " << health << endl;
            if (health <= 0)
            {
                cout << "You have succumbed to your injuries. Game Over." << endl;
                alive = false;
            }
        }

        // Decision 4: The Guardian (Fight or Sneak)
        if (alive == true)
        {
            cout << endl
                 << "STAGE 4: THE GUARDIAN" << endl;
            cout << "A stone guardian blocks the path to the vault. Do you fight it or try to sneak past? (fight/sneak): ";
            getline(cin, command);
            // Check the player's choice and apply damage accordingly.
            if (command == "fight")
            {
                health = health - 70;
                cout << "You engage in battle! The guardian strikes back, dealing 70 damage. Health: " << health << endl;
            }

            else
            {
                health = health - 30;
                cout << "You attempt to sneak past, but the guardian notices you! You take 30 damage. Health: " << health << endl;
            }

            if (health <= 0)
            {
                cout << "You have been defeated by the guardian. Game Over." << endl;
                alive = false;
            }
        }

            // Decision 5: The Vault (Final Decision)
            if (alive == true)
            {
                cout << endl
                     << "STAGE 5: THE VAULT" << endl;
                     // Check if the player has the key to open the vault.
                if (player.hasKey == true)
                {
                    cout << "The key fits the lock! The door swings open." << endl;
                    cout << "You grab the Gold Skull. YOU WIN, " << player.getName() << " the " << player.getHeroType() << "!" << endl;
                }
                else
                {
                    cout << "The vault is locked! Without the key, you cannot retrieve the Gold Skull. Game Over." << endl;
                    alive = false;
                }
            }

            if (alive == false)
            {
                cout << endl
                     << "GAMEOVER. " << player.getName() << " has fallen in Brimstone Keep." << endl;
            }
                // Asking the player if they want to try again after a game over.
                cout << "Would you like to try again? (yes/no): ";
                getline(cin, command);
                if (command == "no")
                {
                    running = false;
                    cout << "Thank you for playing! Goodbye." << endl;
                }
                else
                {
                    cout << "Restarting the game..." << endl;
                }
        }
    

    return 0;
}