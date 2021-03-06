class Member:
    """A member of a university"""

    def __init__(self, name, address, email):
        """(Member, str, str, str) -> NoneType
        Create a new member named name,
        with home address and email address
        """
        self.name = name
        self.address = address
        self.email = email

    def __str__(self):
        """(Member) -> str
        Return a string representation of this Member
        """
        rep = "{}\n{}\n{}".format(self.name, self.address, self.email)
        return rep

class Faculty(Member):
    """A faculty member at a university"""
    

    def __init__(self, name, address, email, faculty_num):
        """(Faculty, str, str, str, str) -> NoneType
        Create a new faculty named name,
        with home address and email address,
        faculty number faculty_num and an empty list of courses.
        """
        super().__init__(name, address, email)
        self.faculty_number = faculty_num
        self.courses_teaching = []

    def __str__(self):
        """(Faculty) -> str
        Return a string representation of this Faculty
        """
        member_string = super().__str__()
        rep = "{}\n{}\nCourses:{}".format(
            member_string, self.faculty_number, self.courses_teaching)
        return rep
        

class Student(Member):
    """A Student member at a university"""
    

    def __init__(self, name, address, email, student_num):
        """(Faculty, str, str, str, str) -> NoneType
        Create a new student named name,
        with home address and email address,
        student number student_num and an empty list of courses taken,
        and an empty list of current courses.
        """
        super().__init__(name, address, email)
        self.student_number = student_num
        self.courses_taken = []
        self.courses_taking = []
