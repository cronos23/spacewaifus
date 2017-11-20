#include <QString>
#include <QtTest>
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
    void testCase1();
    void testReducePointsBelowZero();
    void testReduceCreditsBelowMaxLoan();
    //void testLoanBalance();
};

StatisticsTest::StatisticsTest()
{
}


void StatisticsTest::testCase1()
{
    QVERIFY2(true, "Failure");
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

//void StatisticsTest::testLoanBalance()
//{
//    Statistics test;
//    test.reduceCredits(900);
//    QVERIFY(test.getCreditBalance() == -900);
//}


QTEST_APPLESS_MAIN(StatisticsTest)

#include "statisticstest.moc"
