--In 1.sql, write a SQL query to list the titles of all movies released in 2008.
--Your query should output a table with a single column for the title of each movie.

SELECT title FROM movies
WHERE year = 2008

--In 2.sql, write a SQL query to determine the birth year of Emma Stone.
--Your query should output a table with a single column and a single row (plus optional header) containing Emma Stone’s birth year.
--You may assume that there is only one person in the database with the name Emma Stone.

SELECT birth FROM people 
where name = "Emma Stone"
-- string should be in the ""

--In 3.sql, write a SQL query to list the titles of all movies with a release date on or after 2018, in alphabetical order.
--Your query should output a table with a single column for the title of each movie.
--Movies released in 2018 should be included, as should movies with release dates in the future.

SELECT title FROM movies
WHERE year >= 2018
ORDER BY title ASC

--In 4.sql, write a SQL query to determine the number of movies with an IMDb rating of 10.0.
--Your query should output a table with a single column and a single row (plus optional header) containing the number of movies with a 10.0 rating.

SELECT COUNT(movie_id) FROM ratings 
where rating = 10

--In 5.sql, write a SQL query to list the titles and release years of all Harry Potter movies, in chronological order.
--Your query should output a table with two columns, one for the title of each movie and one for the release year of each movie.
--You may assume that the title of all Harry Potter movies will begin with the words “Harry Potter”, and that if a movie title begins with the words “Harry Potter”, it is a Harry Potter movie.

SELECT title, year FROM movies
WHERE title like 'Harry Potter%'
ORDER BY year

--In 6.sql, write a SQL query to determine the average rating of all movies released in 2012.
--Your query should output a table with a single column and a single row (plus optional header) containing the average rating.

SELECT AVG(rating) FROM ratings
JOIN movies
ON ratings.movie_id = movies.id
WHERE year = 2012

--In 7.sql, write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.
--Your query should output a table with two columns, one for the title of each movie and one for the rating of each movie.
--Movies that do not have ratings should not be included in the result.

SELECT title, rating FROM movies 
join ratings on movies.id = ratings.movie_id
WHERE year = 2010 
ORDER BY rating DESC, title ASC

--In 8.sql, write a SQL query to list the names of all people who starred in Toy Story.
--Your query should output a table with a single column for the name of each person.
--You may assume that there is only one movie in the database with the title Toy Story.

SELECT name FROM people
join stars on people.id = stars.person_id
JOIN movies on stars.movie_id = movies.id
WHERE title = "Toy Story"

--In 9.sql, write a SQL query to list the names of all people who starred in a movie released in 2004, ordered by birth year.
--Your query should output a table with a single column for the name of each person.
--People with the same birth year may be listed in any order.
--No need to worry about people who have no birth year listed, so long as those who do have a birth year are listed in order.
--If a person appeared in more than one movie in 2004, they should only appear in your results once.

SELECT name from people
join stars on people.id = stars.person_id
JOIN movies on stars.movie_id = movies.id
WHERE year = 2004
GROUP BY person_id
ORDER BY birth

--In 10.sql, write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.
--Your query should output a table with a single column for the name of each person.

SELECT COUNT(name) FROM people
JOIN directors ON people.id = directors.person_id 
JOIN ratings ON directors.movie_id = ratings.movie_id
WHERE rating >= 9


--In 11.sql, write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
--Your query should output a table with a single column for the title of each movie.
--You may assume that there is only one person in the database with the name Chadwick Boseman.

SELECT title FROM movies
JOIN ratings ON movies.id = ratings.movie_id
JOIN stars ON ratings.movie_id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE name = "Chadwick Boseman"
ORDER BY rating DESC
LIMIT 5

--In 12.sql, write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
--Your query should output a table with a single column for the title of each movie.
--You may assume that there is only one person in the database with the name Johnny Depp.
--You may assume that there is only one person in the database with the name Helena Bonham Carter.

SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id
Join people ON stars.person_id = people.id
Where name = "Johnny Depp"
INTERSECT
SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id
Join people ON stars.person_id = people.id
Where name = "Helena Bonham Carter"


--In 13.sql, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
--Your query should output a table with a single column for the name of each person.
--There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
--Kevin Bacon himself should not be included in the resulting list.

SELECT DISTINCT COUNT(name) FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE movie_id IN (
SELECT movie_id FROM people
JOIN stars ON people.id = stars.person_id
WHERE name = "Kevin Bacon" AND birth = 1958
)
AND name != "Kevin Bacon"

-- This is from section session
- Write `SELECT` queries to answer these questions:
  -- What is Alice's student id?
  -> SELECT id FROM people WHERE name = "Alice";

  -- What is the course title for CS51?
  -> SELECT title FROM courses WHERE course = "CS50"

  -- What are the course codes and titles for all of the CS courses? (Assume that all CS courses have a course code that begins with 'CS')
  -> SELECT code, titles FROM courses WHERE code LIKE "CS%"

  -- How many courses are there?
  -> SELECT COUNT(*) FROM courses

  -- How many students are taking CS50?
    --- First, do this in two steps
    --- Then, combine into a single nested query
    --- Then, show the same result from joining tables
  -> SELECT COUNT(*) FROM students WHERE course_id in (SELECT id FROM courses Where code = "cs50")
  -> SELECT COUNT(*) FROM students JOIN courses ON students.course_id = course.id WHERE code = "CS50"

  -- What are the names of all of the instructors? Generate a table with all instructors' names and the course they teach.
  ->

  -- What are the names of all of the students taking CS50?
    --- First, do this using JOINs
    --- Then, do this with nested queries
  -> SELECT name FROM PEOPLE JOIN student ON students.person_id =people.id JOIN courses on courses.id = students.course_id WHERE code = "CS50"

- Write some `UPDATE` and `DELETE` queries.
  -- Alice wants to switch from CS50 into CS51
    --- First, do this as a multi-step process
    --- Then, show nested query
  -> UPDATE students SET course_id = (SELECT id FROM courses WHERE code = "cs51") WHERE person_id = (SELECT id FROM people WHERE name = "Alice")

  -- CS182 was cancelled.
  -> DELETE FROM courses WHERE code = "C182"

  ("INSERT INTO people (name) VALUES (?)", name)
- Write a Python program `enroll.py` to add new students to the roster and enroll them in courses.

CREATE TABLE people (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  name TEXT NOT NULL
);
CREATE TABLE sqlite_sequence(name,seq);
CREATE TABLE courses (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  code TEXT NOT NULL,
  title TEXT NOT NULL
);
CREATE TABLE students (
  person_id INTEGER NOT NULL,
  course_id INTEGER NOT NULL
);
CREATE TABLE instructors (
  person_id INTEGER NOT NULL,
  course_id INTEGER NOT NULL
);
