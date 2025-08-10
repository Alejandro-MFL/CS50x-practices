-- Keep a log of any SQL queries you execute as you solve the mystery.
-- See all tables
.tables
-- View the crime scene report structure
.schema crime_scene_reports
-- See scene reports from 7/28/24 on Humphrey Street
SELECT * FROM crime_scene_reports
WHERE year = 2024
AND month = 7
AND day = 28
AND street = 'Humphrey Street';
-- View the interview report structure
.schema interviews
-- See the interviews from 7/28/24 on Humphrey Street where the bakery is mentioned.
SELECT * FROM interviews
WHERE year = 2024
AND month = 7
AND day = 28
AND transcript LIKE '%bakery%';
-- View the structure of phone calls, ATM transactions, and people
--to see if by matching two clues I could get the person's name by license and phone number
.schema phone_calls
.schema bakery_security_logs
.schema people
SELECT name, phone_number, license_plate
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2024
      AND activity = 'exit'
      AND month = 7
      AND day = 28
      AND hour = 10
      AND minute > 10
      AND minute < 26)
AND phone_number IN(
SELECT caller
FROM phone_calls
WHERE year = 2024
     AND month = 7
     AND day = 28
     AND duration <= 60);
-- I check atm_transactions and bank_accounts to see if
-- by integrating the three clues I go from 4 suspects to one
.schema bank_accounts
.schema atm_transactions
-- To be able to do the search correctly, I look at the structure and terms used by atm_transactions.
SELECT *
FROM atm_transactions
WHERE year = 2024
AND month = 7
 AND day = 28
-- I search by adding the bank details, leaving two suspects Diana and Bruce
SELECT name, phone_number, license_plate, id ,  passport_number
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2024
      AND activity = 'exit'
      AND month = 7
      AND day = 28
      AND hour = 10
      AND minute > 10
      AND minute < 26)
AND phone_number IN(
SELECT caller
FROM phone_calls
WHERE year = 2024
     AND month = 7
     AND day = 28
     AND duration <= 60)
AND id IN(
SELECT person_id
       FROM bank_accounts
        WHERE account_number IN (
            SELECT account_number
            FROM atm_transactions
            WHERE year = 2024
              AND month = 7
             AND day = 28
             AND atm_location = 'Leggett Street'
              AND transaction_type = 'withdraw'
));
-- I now look for who they were talking to on the phone,
-- and I extract their name, ID, and account number.
SELECT DISTINCT p.name, b.account_number, p.id
FROM people p
JOIN bank_accounts b
    ON p.id = b.person_id
WHERE p.phone_number IN (
    SELECT receiver
    FROM phone_calls
    WHERE caller IN ('(770) 555-1861', '(367) 555-5533')
    AND year = 2024
     AND month = 7
     AND day = 28
     AND duration <= 60
);
--I review the airports flights passengers structure to know what I will need
.schema passengers
.schema airports
.schema flights
--I'm looking for the airport ID.
SELECT *
FROM airports
WHERE city = 'Fiftyville';
-- I'm looking for information on the first flight leaving Fiftyville the next day, taking the flight ID and the destination airport ID.
SELECT *
FROM flights
WHERE origin_airport_id = 8
AND year = 2024
AND month = 7
AND day = 29
ORDER BY hour, minute;
-- I'm looking for the airport to which the destination ID corresponds, taking the city to which the person has fled.
SELECT *
FROM airports
WHERE id = 4;
-- I check if there are any passengers with the passports of the two suspects. I discover that Bruce is the thief.
SELECT *
FROM passengers
WHERE flight_id = 36
AND passport_number IN (3592750733, 5773159633) ;
-- Finally having the thief I check who he called, Robin being his accomplice
SELECT DISTINCT p.name, b.account_number, p.id
FROM people p
JOIN bank_accounts b
    ON p.id = b.person_id
WHERE p.phone_number IN (
    SELECT receiver
    FROM phone_calls
    WHERE caller = '(367) 555-5533'
    AND year = 2024
     AND month = 7
     AND day = 28
     AND duration <= 60
);

