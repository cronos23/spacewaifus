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
    currentStarSystem_ = givenStarSystem;
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

    QObject::connect(ui->option1_button, &QPushButton::clicked,
                     this, &encounter::close);
    ui->option2_button->setEnabled(false);
    ui->option3_button->setEnabled(false);
    ui->info_button->setEnabled(false);
}

void encounter::setCorrectAnswer()
{
    if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Terraforming)
    {
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::firstRightDialog);

    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Refinery)
    {
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::firstRightDialog);
    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Extraction)
    {
        QObject::connect(ui->option2_button, &QPushButton::clicked,
                         this, &encounter::firstRightDialog);
    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Colony)
    {
        QObject::connect(ui->option2_button, &QPushButton::clicked,
                         this, &encounter::firstRightDialog);
    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::HiTech)
    {
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::firstRightDialog);
    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Industrial
             or currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Tourism)
    {
        QObject::connect(ui->option3_button, &QPushButton::clicked,
                         this, &encounter::firstRightDialog);
    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Agriculture
             or currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Service)
    {
        QObject::connect(ui->option2_button, &QPushButton::clicked,
                         this, &encounter::firstRightDialog);
    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Military)
    {
        QObject::connect(ui->option2_button, &QPushButton::clicked,
                         this, &encounter::firstRightDialog);
    }
    else
    {
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::firstRightDialog);
    }
}


void encounter::infoDialog()
{
    if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Terraforming)
    {
        ui->response_label->setText("There's not that much to say about me...");

    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Refinery)
    {
        ui->response_label->setText("I'm getting old so I'd just like to settle down with someone and share my wealth");
    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Extraction)
    {
        ui->response_label->setText("I haven't met anyone special in the whole starsystem.");
    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Colony)
    {
        ui->response_label->setText("...");
    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::HiTech)
    {
        ui->response_label->setText("I am the best space racer in the galaxy!");
    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Industrial
             or currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Tourism)
    {
        ui->response_label->setText("I'm more fond of shiny things than other ships.");
    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Agriculture
             or currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Service)
    {
        ui->response_label->setText("I just want a strong husbando to take care of me.");
    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Military)
    {
        ui->response_label->setText("I will destroy anyone that's weaker than me.");
    }
    else
    {
        ui->response_label->setText("I wish someone accepted me for who I am.");
    }
}

void encounter::firstRightDialog()
{
    if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Terraforming)
    {
        ui->response_label->setText("Wow, thanks.");
        ui->option1_button->setText("Want to hang out?");
        ui->option2_button->setEnabled(false);
        ui->option3_button->setEnabled(false);
        ui->info_button->setEnabled(false);
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::successfulEncounter);

    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Refinery)
    {
        ui->response_label->setText("Wow, really?");
        ui->option1_button->setText("I wouldn't mind settling down with you.");
        ui->option2_button->setText("Did you say wealth?");
        ui->option2_button->setEnabled(true); // Why is this needed?
        ui->option3_button->setEnabled(false);
        ui->info_button->setEnabled(false);
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::successfulEncounter);
        QObject::connect(ui->option2_button, &QPushButton::clicked,
                         this, &encounter::rejection);
    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Extraction)
    {
        ui->response_label->setText("That's so cool! You really are something else.");
        ui->option1_button->setText("Want to go on an adventure?");
        ui->option2_button->setEnabled(false);
        ui->option3_button->setEnabled(false);
        ui->info_button->setEnabled(false);
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::successfulEncounter);
    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Colony)
    {
        ui->response_label->setText("...");
        ui->option1_button->setText("Okay?");
        ui->option2_button->setEnabled(false);
        ui->option3_button->setEnabled(false);
        ui->info_button->setEnabled(false);
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::successfulEncounter);
    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::HiTech)
    {
        ui->response_label->setText("I like what I'm hearing.");
        ui->option1_button->setText("I'm a fast racer too.");
        ui->option2_button->setText("Can you teach me?");
        ui->option2_button->setEnabled(true); // Why is this needed?
        ui->option3_button->setEnabled(false);
        ui->info_button->setEnabled(false);
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::successfulEncounter);
        QObject::connect(ui->option2_button, &QPushButton::clicked,
                         this, &encounter::rejection);
    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Industrial
             or currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Tourism)
    {
        ui->response_label->setText("You have my attention..");
        ui->option1_button->setText("There's more to me than just money.");
        ui->option2_button->setText("*Give more money*");
        ui->option2_button->setEnabled(true); // Why is this needed?
        ui->option3_button->setEnabled(false);
        ui->info_button->setEnabled(false);
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::rejection);
        QObject::connect(ui->option2_button, &QPushButton::clicked,
                         this, &encounter::successfulEncounter);
    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Agriculture
             or currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Service)
    {
        ui->response_label->setText("You are so kawaii!");
        ui->option1_button->setText("What alien language is that?");
        ui->option2_button->setText("You're cute too.");
        ui->option2_button->setEnabled(true); // Why is this needed?
        ui->option3_button->setEnabled(false);
        ui->info_button->setEnabled(false);
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::rejection);
        QObject::connect(ui->option2_button, &QPushButton::clicked,
                         this, &encounter::successfulEncounter);
    }
    else if (currentStarSystem_->getEconomy() == Common::StarSystem::ECONOMY_TYPE::Military)
    {
        ui->response_label->setText("Omae Wa Mou Shindeiru");
        ui->option1_button->setText("NANI!?");
        ui->option2_button->setText("*Teleports behind her*");
        ui->option2_button->setEnabled(true); // Why is this needed?
        ui->option3_button->setEnabled(false);
        ui->info_button->setEnabled(false);
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::rejection);
        QObject::connect(ui->option2_button, &QPushButton::clicked,
                         this, &encounter::successfulEncounter);
    }
    else
    {
        ui->response_label->setText("I'm not an ordinary spaceship...");
        ui->option1_button->setText("It's a trap.");
        ui->option2_button->setEnabled(false);
        ui->option3_button->setEnabled(false);
        ui->info_button->setEnabled(false);
        QObject::connect(ui->option1_button, &QPushButton::clicked,
                         this, &encounter::successfulEncounter);
    }

}

void encounter::successfulEncounter()
{
    ui->response_label->setText("*You have succeeded in the art of seduction.*");
    ui->option1_button->setText("*Leave*");
    ui->option2_button->setEnabled(false);
    ui->option3_button->setEnabled(false);
    ui->info_button->setEnabled(false);
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
