import psycopg2
from urllib.parse import urlparse


# Configuration Options

database_url = '' # Valid Postgres Database URL 


# Parse the database url using the urlparse function

parsed_url = urlparse(database_url)
username = parsed_url.username
password = parsed_url.password
database = parsed_url.path[1:]
hostname = parsed_url.hostname

# Open a connection and create a cursor using the parsed url

db = psycopg2.connect(database=database, user=username, password=password, host=hostname)
c = db.cursor()


# Create table as per the specification document

c.execute("""CREATE TABLE IF NOT EXISTS Students(
                      ID TEXT,
                      Category TEXT,
                      Stream TEXT,
                      Name TEXT,
                      Qualification TEXT,
                      Aim TEXT,
                      Skills ARRAY)""")


def create_student_if_not_exists(id: str, category: str, stream: str, name: str, qualification: str, aim: str, skills: list):

    # Get amount of students with ID corresponding to the inputted one
    # Since IDs are unique we assume that if there's a user with that ID already 

    c.execute("SELECT COUNT(*) FROM Students WHERE ID=%s", (str(id),))

    # Get the results from the SQL query

    studentCount = c.fetchone()[0]

    # Check if the count isn't above 0

    if studentCount < 1:

        # Create student in dB based off inputted values

        c.execute("INSERT INTO Students VALUES (%s, %s, %s, %s, %s, %s, %s)", (str(id), str(category), str(stream), str(qualification), str(aim), list(skills)))
        db.commit()

def get_student_from_database(id: str):

    # Get a student with a specified ID from the database and return it as a tuple

    c.execute("SELECT * FROM Students WHERE ID=%s", (str(id),))
    return c.fetchone()[0]
