#include "encounter.hh"
#include "ui_encounter.h"

encounter::encounter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::encounter)
{
    ui->setupUi(this);

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
    ui->response_label->setText("Well this isn't going anywhere...");
    ui->option1_button->setText("Leave");
    ui->option2_button->setText("");
    ui->option3_button->setText((""));
    ui->info_button->setText("");
}

//kuva starsystemist
//she says
//valinnat

//1. Compliment
//2. Brag
//3. Bribe
//4. Info

//Hey there!

//Terraforming:
//Info : "There's not much to say about me..."
//1. Compliment
//"wow thanks"
//1.Want to hang out?

//Refinery:
//Info : I'm getting old so i'd just like to settle down with someone and share my wealth
//1. compliment
//"Wow really?"
//1. I wouldnt mind settling down with you
//2. Did you say wealth?
//(rahaa)

//Extraction:
//Info: "I havent met anyone special in the whole starsystem"
//2. Brag
//"That's so cool! You really are something else"
//1. Want to go on an adventure?

//Colony:
//Info: "..."
//2. Brag
//"..."
//1. Okay

//HiTech:
//Info: "I am the best space racer in the galaxy!"
//1. Compliment
//"I like what i'm hearing"
//1. I'm a fast racer too
//2. Can you teach me?

//Industrial/Tourism:
//Info: I'm more fond of shiny things than other ships
//3. Bribe
//"You have my attention."
//1. There's more to me than just money
//2. Give more money

//Agriculture/Service:
//Info: "I just want a strong husbando to take care of me"
//2. Brag
//"You are so kawaii!"
//1. You are cute too
//2. What alien language is that?

//Military:
//Info: "I will destroy anyone that's weaker than me"
//2. Brag
//"Omae Wa Mou Shindeiru"
//1.NANI?
//2.*Teleports behind her*

//None:
//Info: "I wish someone accepted me for who i am"
//1. Compliment
//"I'm not an ordinary spaceship..."
//1. It's a trap
