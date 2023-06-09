#include <iostream>
#include <fstream>
#include "cpr/cpr.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std::chrono;

int main()
{
    std::ofstream fout;

    std::string address[15] = {"Bgv2TzQL8ojRZZiCJk1EVaQxgsudoorJmPU8nTbEqJE5T1wskaDQY9hN1Y9fE31xGf1NSWCwVU3ud4S8zPgRXU8bSL1rWGb", "BfFZoXzjbtd2Wk1cX92bhxGsiaJHn82jV36Mg4Ry3wSjUgxVFwH5zoNRSM6RSWHUj5RC5yvejGBAGD3FPrMZdeYcDFtspdM", "Bh2QYCy9tuA5dNdsV5kBiTWA6vVfqPXCkUtdFvXei5FhSyVmRZ3WYqpDFennh319iG5gtRdSKQ9mKN8QCt8a5V3z9Qu2wiC", "BhTfaK32QUcAY3XjESkGQYZwjkwwgLkR1GUuWSeMgZZ25xYd1Uz1D7rKND1auwQLNqMkxEXxwArTwRrUeHy53Li4SHUboVk", "BZPMCqBkAWoUT4PvEnZ6BKYCbfrtd3h4iNJ8WxFPir81QpKSYJnCqYbd56oDc8C4o287W9KfyFEPE352EpzXa7GxVPLp8PR", "BZKKox6GzCiWnWXz5Tz4Hw1q7xVXAxGCDapCxTVszLswWf7X186xQo72gWWLuUdJ5y2vyFq8B81FoJUsGXRqnSJgFRqJrcV", "BZ8x7qAXixVZtBQhZzhiXbB5yP9mgYiNr5erDvPyh2NYERKkSgpQjcPhwczGvkxYa5TLyYTK4R5386nB2PxK162BH3NjHUe", "BYfy7gEN1t2GMKJ56Jcm6NgRVZhnbqoFVLmdnycRjeUzR3LUaJ2QLdP4tef1BXLz6kUNSoVYSU89zjCktcqoJFsUPxS4hL8", "BgkwTDiNaLGEVqdoYUzyKbPrpMMVvhrLuGAAoHkSCo6uNbdEPwLRmvJ65kYvhrUDkBdyFzUDWhCd61fu6QMTH1bm5B2wXRp", "BbUPYDkwhyyjMUgv5Tmc4Z11MsnSqaXNSL2kgCdvmT9jT9411xjRZWUN3nNmXYe9B9enU1wqEQRqZS8cSsUp8AhbDZsVywD", "BbKtLm9LfgkR3PG4egzfGLSwN9Y5pc4mR7G1s7ZMTYi3ASFfnnXetgDLnw21QjupqNHqQp3MXeCPUfw9wBRzzvNVKxKzUou", "BcaubWMHaXKfUuxwugG18MdqxMWTVmNSyYvLm9qgdCMFEKWVBSeUHqZVQzDNR3wzzANdCcXQQPKTuQ2me9kjoVr3Ttbq7R7", "BYBfQykxDCugjD4YH2nGCM197DaCW89VXGrim3EEScHXci9SUvstKGLi5NAnKzXqsPbz2UCP2SVEoMK4F9bT1ep45NcHQdR", "Bhr4WEd2CYvBVPnWyNBomQfedH4K9vrp1EL1BRDPh6HNiEMnGcMZgQHMFvBmto1jGSVwkFy8TPKy9U5B1agcTFvuMXGU2cP", "Bgwvwsz4Db6UFZM3Aci1z3eJGC1zDfQHQWnqAfVbSrMzT1fF6o8CZdY7e9PRC6ctUT1TqSfNvhnwFRsqGtRkLNHVVq1uofg"};
    // std::string address[2] = {"Bhr4WEd2CYvBVPnWyNBomQfedH4K9vrp1EL1BRDPh6HNiEMnGcMZgQHMFvBmto1jGSVwkFy8TPKy9U5B1agcTFvuMXGU2cP", "Bgwvwsz4Db6UFZM3Aci1z3eJGC1zDfQHQWnqAfVbSrMzT1fF6o8CZdY7e9PRC6ctUT1TqSfNvhnwFRsqGtRkLNHVVq1uofg"};
    int size = sizeof(address) / sizeof(address[0]);

    std::cout << "size: " << size << std::endl;
    for (int j = 0; j < 20; j++)
    {
        
        for (int i = 0; i < size; i++)
        {
            fout.open("txhash.csv", std::ios::app);
            // std::cout << "address : " << address[i] << std::endl;
            // curl -X POST http://209.126.86.103:19092/json_rpc -d '{"jsonrpc":"2.0","id":"0","method":"transfer","params":{"destinations":[{"amount":10000000000,"address":"9vWA8m33BzXi1mUj5a8eWr9AaWCas4oLKEsn8y3ZmjLXU3CG4K4caRg1uKwARj9AVtcMjRALMYdfTPM6J2JTYKpM9Jxj5rz"}],"account_index":0,"subaddr_indices":[0],"priority":1,"ring_size":7,"get_tx_key": true}}' -H 'Content-Type: application/json'

            json transferBody = {
                {"jsonrpc", "2.0"},
                {"id", "0"},
                {"method", "transfer"},
                {"params", {{"destinations", {{{"amount", 2000000000}, {"address", address[i]}}}}, {"account_index", 0}, {"subaddr_indices", {0}}, {"priority", 0}, {"ring_size", 7}, {"get_tx_key", true}}}};

            while (true)
            {
                cpr::Response res = cpr::Post(cpr::Url{"http://209.126.86.103:19092/json_rpc"},
                                              cpr::Body{transferBody.dump()},
                                              cpr::Header{{"Content-Type", "application/json"}});

                // std::cout << res.text << std::endl;

                json resultTx = json::parse(res.text);
                // std::cout << resultTx.dump() << std::endl;

                if (resultTx.contains("error"))
                {
                    if (resultTx["error"]["code"] != -2)
                    {
                        if (resultTx["error"]["code"] == -37)
                        {
                            std::cout << "not enough money\n";
                            std::this_thread::sleep_for(std::chrono::seconds(70));
                            continue;
                        }
                        std::cout << "output distribution\n";
                        std::this_thread::sleep_for(std::chrono::seconds(10));
                        continue;
                    }
                    std::cout << resultTx["error"]["message"] << "\n";
                    fout.close();
                    return 0;
                }
                std::cout << "address id : " <<j <<":" << i << " address : " << address[i] << std::endl;
                fout << resultTx["result"]["tx_hash"] << "\n";
                fout.close();
                break;
            }
            std::this_thread::sleep_for(std::chrono::seconds(10));
        }
        
    }
    return 0;
}