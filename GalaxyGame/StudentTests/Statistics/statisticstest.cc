#include "statistics.hh"
#include <QString>
#include <QtTest>
<<<<<<< HEAD
#include <memory>

=======
#include "statistics.hh"
#include "stateexception.hh"
using namespace Student;
using namespace Common;
>>>>>>> 5857e1c798a9095a2018cc49c574199c0c1ede06
class StatisticsTest : public QObject
{
    Q_OBJECT

public:
    StatisticsTest();

private Q_SLOTS:
<<<<<<< HEAD
    void init();
=======
    void testCase1();
    void testReducePointsBelowZero();

>>>>>>> 5857e1c798a9095a2018cc49c574199c0c1ede06
};

StatisticsTest::StatisticsTest() {
}


void StatisticsTest::init() {
}

void StatisticsTest::testReducePointsBelowZero()
{
    Statistics stat;
    stat.addPoints(10);
    QVERIFY_EXCEPTION_THROWN(stat.reducePoints(20), StateException);
}




QTEST_APPLESS_MAIN(StatisticsTest)

#include "statisticstest.moc"
