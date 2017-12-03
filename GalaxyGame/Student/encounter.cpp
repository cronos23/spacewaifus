#include "encounter.hh"
#include "ui_encounter.h"

encounter::encounter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::encounter)
{
    ui->setupUi(this);

    QObject::connect(ui->option1_button, &QPushButton::clicked,
                     this, &encounter::rejection);
    QObject::connect(ui->option2_button, &QPushButton::clicked,
                     this, &encounter::rejection);
    QObject::connect(ui->option3_button, &QPushButton::clicked,
                     this, &encounter::rejection);
    QObject::connect(ui->info_button, &QPushButton::clicked,
                     this, &encounter::infoDialog);

}

encounter::~encounter()
{
    delete ui;
}

void encounter::setStarSystem(std::shared_ptr<Common::StarSystem> givenStarSystem)
{
    Common::StarSystem::ECONOMY_TYPE currentStarSystemEconomy = givenStarSystem->getEconomy();
    MainWindowUtility util;
    waifuType_ = util.getWaifuType(currentStarSystemEconomy);
    std::ostringstream responseText;
    responseText << "A " << waifuType_ << " spaceship appears!" <<
                    "\n\nIt says: Hey there~";
    std::string responseTextstr = responseText.str();
    ui->response_label->setText(QString::fromStdString(responseTextstr));
    QPixmap WaifuPic;
    if (currentStarSystemEconomy < 4) {
        WaifuPic.load(":/images/images/starship_teal.png");
    } else if (currentStarSystemEconomy < 7){
        WaifuPic.load(":/images/images/starship_yellow.png");
    } else if (currentStarSystemEconomy < 10) {
        WaifuPic.load(":/images/images/starship_green.png");
    } else {
        WaifuPic.load(":/images/images/starship_blue.png");
    }
    ui->picture_label->setPixmap(WaifuPic);

    setCorrectAnswer();
}


void encounter::rejection()
{
//    QPixmap waifuPic;
//    waifuPic.load(":/images/images/starship_teal.png");
//    ui->picture_label->setPixmap(waifuPic);
//    ui->picture_label->show();
    ui->response_label->setText("Well this isn't going anywhere...");
    ui->option1_button->setText("Leave");
    ui->option2_button->setText("");
    ui->option3_button->setText((""));
    ui->info_button->setText("");

    outcome_ = Lost;

    QObject::connect(ui->option1_button, &QPushButton::clicked,
                     this, &encounter::close);
    ui->option2_button->setEnabled(false);
    ui->option3_button->setEnabled(false);
    ui->info_button->setEnabled(false);
}

void encounter::setStatistics(Student::Statistics &stats) {
    if (outcome_ == Lost) {
        stats.addLostShip();
    } else if (outcome_ == SavedNormal) {
        stats.addSavedShip();
        stats.addPoints(100);
    } else if (outcome_ == SavedWealthy) {
        stats.addSavedShip();
        stats.addPoints(100);
        stats.addCredits(2000);
    } else if (outcome_ == SavedBribe) {
        try {
            stats.reduceCredits(500);
            stats.addSavedShip();
            stats.addPoints(200);
        }
        catch (Common::StateException) {
            QMessageBox noMonies;
            noMonies.setText("You don't have enough credits to pay the offered bribe."
                             "\nThe spaceship leaves..");
            noMonies.exec();
            stats.addLostShip();
        }
    }
}

void encounter::setCorrectAnswer()
{
    if (waifuType_ == "Dandere" or waifuType_ == "Wealthy"
            or waifuType_ == "Kamidere" or waifuType_ == "Special") {
        QObject::disconnect(ui->option1_button, &QPushButton::clicked, this, &encounter::rejection);
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::firstRightDialog);

    } else if (waifuType_ == "Yandere" or waifuType_ == "Kuudere"
               or waifuType_ == "Deredere" or waifuType_ == "Tsundere") {

        QObject::disconnect(ui->option2_button, &QPushButton::clicked, this, &encounter::rejection);
        QObject::connect(ui->option2_button, &QPushButton::clicked,
                         this, &encounter::firstRightDialog);

    } else if (waifuType_ == "Greedy") {

        QObject::disconnect(ui->option3_button, &QPushButton::clicked, this, &encounter::rejection);
        QObject::connect(ui->option3_button, &QPushButton::clicked,
                         this, &encounter::firstRightDialog);

    }
}


void encounter::infoDialog()
{
    if (waifuType_ == "Dandere") {
        ui->response_label->setText("There's not that much to say about me...");

    } else if (waifuType_ == "Wealthy") {
        ui->response_label->setText("I'm getting old so I'd just like to settle down with someone and share my wealth");

    } else if (waifuType_ == "Yandere") {
        ui->response_label->setText("I haven't met anyone special in the whole starsystem..");

    } else if (waifuType_ == "Kuudere") {
        ui->response_label->setText("...");

    } else if (waifuType_ == "Kamidere") {
        ui->response_label->setText("I am the best space racer in the galaxy!");

    } else if (waifuType_ == "Greedy") {
        ui->response_label->setText("I'm more fond of shiny things than other ships.");

    } else if (waifuType_ == "Deredere") {
        ui->response_label->setText("I just want a strong husbando to take care of me.");

    } else if (waifuType_ == "Tsundere") {
        ui->response_label->setText("I will destroy anyone that's weaker than me.");

    } else {
        ui->response_label->setText("I wish someone accepted me for who I am.");
    }
}

void encounter::firstRightDialog()
{
    ui->info_button->setEnabled(false);
    ui->info_button->setText("");
    ui->option3_button->setEnabled(false);
    ui->option3_button->setText("");

    if (waifuType_ == "Dandere") {
        ui->response_label->setText("Wow, thanks.");
        ui->option1_button->setText("Want to hang out?");
        ui->option2_button->setEnabled(false);
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::successfulEncounter);

    } else if (waifuType_ == "Wealthy") {
        ui->response_label->setText("Wow, really?");
        ui->option1_button->setText("Did you say wealth?");
        ui->option2_button->setText("I wouldn't mind settling down with you.");
        ui->option2_button->setEnabled(true);
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::rejection);
        QObject::connect(ui->option2_button, &QPushButton::clicked,
                         this, &encounter::successfulEncounter);

    } else if (waifuType_ == "Yandere") {
        ui->response_label->setText("That's so cool! You really are something else.");
        ui->option1_button->setText("Want to go on an adventure?");
        ui->option2_button->setText("");
        ui->option2_button->setEnabled(false);
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::successfulEncounter);

    } else if (waifuType_ == "Kuudere") {
        ui->response_label->setText("...");
        ui->option1_button->setText("Okay?");
        ui->option2_button->setEnabled(false);
        ui->option2_button->setText("");
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::successfulEncounter);

    } else if (waifuType_ == "Kamidere") {
        ui->response_label->setText("I like what I'm hearing.");
        ui->option1_button->setText("I'm a fast racer too.");
        ui->option2_button->setText("Can you teach me?");
        ui->option2_button->setEnabled(true);
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::successfulEncounter);
        QObject::connect(ui->option2_button, &QPushButton::clicked,
                         this, &encounter::rejection);

    } else if (waifuType_ == "Greedy") {
        ui->response_label->setText("You have my attention..");
        ui->option1_button->setText("There's more to me than just money.");
        ui->option2_button->setText("*Offer more money*");
        ui->option2_button->setEnabled(true);
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::successfulEncounter);
        QObject::connect(ui->option2_button, &QPushButton::clicked,
                         this, &encounter::rejection);

    } else if (waifuType_ == "Deredere") {
        ui->response_label->setText("You are so kawaii!");
        ui->option1_button->setText("What alien language is that?");
        ui->option2_button->setText("You're cute too.");
        ui->option2_button->setEnabled(true);
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::rejection);
        QObject::connect(ui->option2_button, &QPushButton::clicked,
                         this, &encounter::successfulEncounter);

    } else if (waifuType_ == "Tsundere") {
        ui->response_label->setText("Omae Wa Mou Shindeiru");
        ui->option1_button->setText("NANI!?");
        ui->option2_button->setText("*Teleports behind her*");
        ui->option2_button->setEnabled(true);
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::rejection);
        QObject::connect(ui->option2_button, &QPushButton::clicked,
                         this, &encounter::successfulEncounter);

    } else {
        ui->response_label->setText("I'm not an ordinary spaceship... ku ku ku");
        ui->option1_button->setText("It's a trap.");
        ui->option2_button->setEnabled(false);
        ui->option2_button->setText("");
        QObject::disconnect(ui->option1_button, &QPushButton::clicked,
                            this, &encounter::firstRightDialog);
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::successfulEncounter);
    }
}

void encounter::successfulEncounter()
{
    ui->response_label->setText("*You have succeeded in the art of seduction.*");
//    QObject::disconnect(ui->option1_button, &QPushButton::clicked,
//                     this, &encounter::rejection);
//    QObject::disconnect(ui->option2_button, &QPushButton::clicked,
//                     this, &encounter::rejection);
//    QObject::disconnect(ui->option3_button, &QPushButton::clicked,
//                     this, &encounter::rejection);
    QObject::connect(ui->info_button, &QPushButton::clicked,
                     this, &encounter::close);
    ui->option1_button->setEnabled(false);
    ui->option1_button->setText("");
    ui->option2_button->setEnabled(false);
    ui->option2_button->setText("");
    ui->option3_button->setEnabled(false);
    ui->option3_button->setText("");
    ui->info_button->setEnabled(true);
    ui->info_button->setText("*Leave*");
    outcome_ = SavedNormal;
    if (waifuType_ == "Greedy") {
        outcome_ = SavedBribe;
    } else if (waifuType_ == "Wealthy") {
        outcome_ = SavedWealthy;
    }


}




//kuva starsystemist
//she says
//valinnat

//1. Compliment
//2. Brag
//3. Bribe
//4. Info

//Hey there!

//Terraforming: 1
//Info : "There's not much to say about me..."
//1. Compliment
//"wow thanks"
//1.Want to hang out?

//Refinery: 2
//Info : I'm getting old so i'd just like to settle down with someone and share my wealth
//1. compliment
//"Wow really?"
//1. I wouldnt mind settling down with you
//2. Did you say wealth?
//(rahaa)

//Extraction: 3
//Info: "I havent met anyone special in the whole starsystem"
//2. Brag
//"That's so cool! You really are something else"
//1. Want to go on an adventure?

//Colony: 4
//Info: "..."
//2. Brag
//"..."
//1. Okay

//HiTech: 5
//Info: "I am the best space racer in the galaxy!"
//1. Compliment
//"I like what i'm hearing"
//1. I'm a fast racer too
//2. Can you teach me?

//Industrial/Tourism: 6
//Info: I'm more fond of shiny things than other ships
//3. Bribe
//"You have my attention."
//1. There's more to me than just money
//2. Give more money

//Agriculture/Service: 7
//Info: "I just want a strong husbando to take care of me"
//2. Brag
//"You are so kawaii!"
//1. You are cute too
//2. What alien language is that?

//Military: 8
//Info: "I will destroy anyone that's weaker than me"
//2. Brag
//"Omae Wa Mou Shindeiru"
//1.NANI?
//2.*Teleports behind her*

//None: 9
//Info: "I wish someone accepted me for who i am"
//1. Compliment
//"I'm not an ordinary spaceship..."
//1. It's a trap
