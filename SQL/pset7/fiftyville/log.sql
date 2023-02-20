-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description, street FROM crime_scene_reports WHERE day = 28 AND month = 7 AND street = "Chamberlin Street";

-- Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
-- Interviews were conducted today with three witnesses who were present at the time.
-- each of their interview transcripts mentions the courthouse.

SELECT name, transcript FROM interviews WHERE day = 28 AND month = 7 AND year = 2020;

/*
    Ruth | Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
    If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
*/

/*
    Eugene | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse,
    I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
*/

/*
    Raymond | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
    In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
    The thief then asked the person on the other end of the phone to purchase the flight ticket.
*/

SELECT * FROM courthouse_security_logs WHERE day = 28 AND month = 7 AND year = 2020;

SELECT id FROM airports WHERE city = "Fiftyville";

-- Fiftyville is the 8 id;

-- Looking for earliest flight in the next day
SELECT * FROM flights WHERE day = 29 AND month = 7 AND year = 2020 and origin_airport_id = 8 ORDER BY day, hour;

-- id | origin_airport_id | destination_airport_id | year | month | day | hour | minute
-- 36 | 8 | 4 | 2020 | 7 | 29 | 8 | 20
-- The destination airport is the 4 one

SELECT * FROM airports WHERE id = 4;

-- 4 airport: LHR | Heathrow Airport | London
-- The thief ran away to London


/* 
    Getting together all conditions to find the thief such as courthouse security logs schedules, transction and phone call made by the thief
    in the theft hour and day
*/

SELECT * FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON flights.id = passengers.flight_id
JOIN courthouse_security_logs ON courthouse_security_logs.license_plate = people.license_plate
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN bank_accounts ON bank_accounts.person_id = people.id
WHERE courthouse_security_logs.day = 28 AND courthouse_security_logs.month = 7 AND courthouse_security_logs.year = 2020 AND courthouse_security_logs.hour = 10
AND courthouse_security_logs.minute <= 25 AND courthouse_security_logs.activity = "exit" AND passengers.flight_id = 36 AND phone_calls.duration < 60
AND phone_calls.day = 28 AND phone_calls.month = 7 AND phone_calls.year = 2020;

--The thief is Ernest
-- (375) 555-8161 is the number that Ernest called

-- Looking for the person who helped Ernest

SELECT name FROM people WHERE phone_number = "(375) 555-8161";

-- The person who helped Ernest was Berthold

-- Ernest stole our dear duck and ran away to London with Berthold help.