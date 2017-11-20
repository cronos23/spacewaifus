#include "statistics.hh"
#include <QString>
#include <QtTest>
#include <memory>
#include "statistics.hh"
#include "stateexception.hh"
using namespace Student;
using namespace Common;
class StatisticsTest : public QObject
{
    Q_OBJECT

public:
    StatisticsTest();

private Q_SLOTS:
    void init();
//    void testCase1();
    void testReducePointsBelowZero();


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
