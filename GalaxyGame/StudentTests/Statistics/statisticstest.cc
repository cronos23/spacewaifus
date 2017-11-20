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
    void testCase1();
    void testReducePointsBelowZero();
    void testReduceCreditsBelowMaxLoan();
};

StatisticsTest::StatisticsTest() {
}


void StatisticsTest::init() {
}

void StatisticsTest::testReducePointsBelowZero()
{
    Statistics test;
    test.addPoints(10);
    QVERIFY_EXCEPTION_THROWN(test.reducePoints(20), StateException);
}

void StatisticsTest::testReduceCreditsBelowMaxLoan()
{
    Statistics test;
    QVERIFY_EXCEPTION_THROWN(test.reduceCredits(1001), StateException);

}


QTEST_APPLESS_MAIN(StatisticsTest)

#include "statisticstest.moc"
