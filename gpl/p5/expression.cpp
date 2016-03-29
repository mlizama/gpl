#include "expression.h"
#include "variable.h"
#include <sstream>
#include <cmath>
#include "math.h"
#include "error.h"
#include <string>
#include <assert.h>     /* assert */

Expression::Expression(int i_value)
{
	int_value = i_value;//set int value
	str_value = "";//default string if not string
	dbl_value = 0.0;//default double if not double
	leftxp = NULL;
	rightxp = NULL;
	m_type = INT;//type is INT
	m_variable = NULL;
	m_kind = CONSTANT;
	//ignore o_type
	o_type = TOUCHES;

}
Expression::Expression(Variable *variable)
{
	int_value = 0;//not used
	str_value = "";//not used
	dbl_value = 0.0;//not used
	//ignore o_type 
	o_type = TOUCHES;
	m_kind = VARIABLE;
	leftxp = NULL;
	rightxp = NULL;
	m_variable = variable;
	m_type = variable->get_type();
	
}
Expression::Expression(Expression *exp, Operator_type type)
{
	int_value = 0;//not used
	str_value = "";//not used
	dbl_value = 0.0;//not used
	o_type = type;
	rightxp = exp;
	m_kind = EXPRESSION;
	//return double
	if(o_type == COS || o_type == SIN || o_type == TAN || o_type == ACOS || o_type == ASIN || o_type == ATAN
	   || o_type == SQRT)
	{
		m_type = DOUBLE;
	}
	else if(o_type == FLOOR || o_type == RANDOM || o_type == NOT)
	{
		m_type = INT;
	}
	else if(o_type == UNARY_MINUS || o_type == ABS)
	{
		m_type = exp->get_type();	
	}
}
Expression::Expression(Expression *left, Operator_type type, Expression *right)
{
	int_value = 0;//not used
	str_value = "";//not used
	dbl_value = 0.0;//not used
	leftxp = left;
	rightxp = right;
	m_kind = EXPRESSION;
	o_type = type;
	m_variable = NULL;
	//these operators only return an int
	if(o_type == LESS_THAN || o_type == LESS_THAN_EQUAL || o_type == GREATER_THAN || o_type == GREATER_THAN_EQUAL ||
	   o_type == AND || o_type == OR || o_type == EQUAL || o_type == NOT_EQUAL)
	{
		m_type = INT;
	}
	//if either left or right are strings then the expression evals to string covers arithmetic operators
	else if(left->get_type() == STRING || left->get_type() == STRING)
	{
		m_type = STRING;

	}
	//if either left or right are doubles then we know the result is double, strings take 
	else if(left->get_type() == DOUBLE || right->get_type() == DOUBLE)
	{
		m_type = DOUBLE;
	}
	//both left and right are int so result must be int
	else if(left->get_type() == INT || right->get_type() == INT)
	{
		m_type = INT;
	}

}

Expression::Expression(double d_value)
{
	int_value = 0;//default int if not int
	str_value = "";//default string if not string
	dbl_value = d_value;//set double value
	leftxp = NULL;
	rightxp = NULL;
	m_type = DOUBLE;//type is INT
	m_variable = NULL;
	m_kind = CONSTANT;
	//ignore o_type
	o_type = TOUCHES;

}
Expression::Expression(string s_value)
{
	int_value = 0;//default int if not int
	str_value = s_value;//set string value
	dbl_value = 0.0;//default double if not double
	leftxp = NULL;
	rightxp = NULL;
	m_type = STRING;//type is INT
	m_variable = NULL;
	m_kind = CONSTANT;
	//ignore o_type
	o_type = TOUCHES;

}

int Expression::eval_int()
{

	if(m_kind == CONSTANT && m_type == INT)
	{
		return int_value;
	}
	else if(m_kind == VARIABLE)
	{
		return m_variable->get_int_value();
	}
	else if(m_kind == EXPRESSION){
		if(o_type == MULTIPLY)
		{
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_double() * rightxp->eval_double();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == INT)
			{
				return leftxp->eval_int() * rightxp->eval_int();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_int() * rightxp->eval_double();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == INT)
			{
				return leftxp->eval_double() * rightxp->eval_int();
			}
		}
		else if(o_type == DIVIDE)
		{
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_double() / rightxp->eval_double();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == INT)
			{
				return leftxp->eval_int() / rightxp->eval_int();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_int() / rightxp->eval_double();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == INT)
			{
				return leftxp->eval_double() / rightxp->eval_int();
			}
		}
		else if(o_type == LESS_THAN)
		{
			
			std::stringstream stream;
			if(leftxp->get_type() == STRING && rightxp->get_type() == STRING)
			{
				return leftxp->eval_string() < rightxp->eval_string();
			}
			if(leftxp->get_type() == STRING && rightxp->get_type() == INT)
			{


				stream << rightxp->eval_int();


				return leftxp->eval_string() < stream.str();
				
			}
			if(leftxp->get_type() == STRING && rightxp->get_type() == DOUBLE)
			{
				stream << rightxp->eval_double();

				return leftxp->eval_string() < stream.str();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == STRING)
			{
				stream << leftxp->eval_int();
				return stream.str() < rightxp->eval_string();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == STRING)
			{
				stream << leftxp->eval_double();
				return stream.str() < rightxp->eval_string();
			}
			//----------------------------------------------------------------------
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_double() < rightxp->eval_double();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == INT)
			{
				return leftxp->eval_int() < rightxp->eval_int();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_int() < rightxp->eval_double();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == INT)
			{
				return leftxp->eval_double() < rightxp->eval_int();
			}
		}
		else if(o_type == LESS_THAN_EQUAL)
		{
			
			std::stringstream stream;
			if(leftxp->get_type() == STRING && rightxp->get_type() == STRING)
			{
				return leftxp->eval_string() <= rightxp->eval_string();
			}
			if(leftxp->get_type() == STRING && rightxp->get_type() == INT)
			{
				stream << rightxp->eval_int();
				return leftxp->eval_string() <= stream.str();
			}
			if(leftxp->get_type() == STRING && rightxp->get_type() == DOUBLE)
			{
				stream << rightxp->eval_double();

				return leftxp->eval_string() <= stream.str();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == STRING)
			{
				stream << leftxp->eval_int();
				return stream.str() <= rightxp->eval_string();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == STRING)
			{
				stream << leftxp->eval_double();
				return stream.str() <= rightxp->eval_string();
			}
			//----------------------------------------------------------------------
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_double() <= rightxp->eval_double();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == INT)
			{
				return leftxp->eval_int() <= rightxp->eval_int();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_int() <= rightxp->eval_double();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == INT)
			{
				return leftxp->eval_double() <= rightxp->eval_int();
			}
		}
		else if(o_type == GREATER_THAN)
		{
			
			std::stringstream stream;
			if(leftxp->get_type() == STRING && rightxp->get_type() == STRING)
			{
				return leftxp->eval_string() > rightxp->eval_string();
			}
			if(leftxp->get_type() == STRING && rightxp->get_type() == INT)
			{
				stream << rightxp->eval_int();
				return leftxp->eval_string() > stream.str();
			}
			if(leftxp->get_type() == STRING && rightxp->get_type() == DOUBLE)
			{
				stream << rightxp->eval_double();

				return leftxp->eval_string() > stream.str();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == STRING)
			{
				stream << leftxp->eval_int();
				return stream.str() > rightxp->eval_string();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == STRING)
			{
				stream << leftxp->eval_double();
				return stream.str() > rightxp->eval_string();
			}
			//----------------------------------------------------------------------
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_double() > rightxp->eval_double();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == INT)
			{
				return leftxp->eval_int() > rightxp->eval_int();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_int() > rightxp->eval_double();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == INT)
			{
				return leftxp->eval_double() > rightxp->eval_int();
			}
		}
		else if(o_type == GREATER_THAN_EQUAL)
		{
			
			std::stringstream stream;
			if(leftxp->get_type() == STRING && rightxp->get_type() == STRING)
			{
				return leftxp->eval_string() >= rightxp->eval_string();
			}
			if(leftxp->get_type() == STRING && rightxp->get_type() == INT)
			{
				stream << rightxp->eval_int();
				return leftxp->eval_string() >= stream.str();
			}
			if(leftxp->get_type() == STRING && rightxp->get_type() == DOUBLE)
			{
				stream << rightxp->eval_double();

				return leftxp->eval_string() >= stream.str();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == STRING)
			{
				stream << leftxp->eval_int();
				return stream.str() >= rightxp->eval_string();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == STRING)
			{
				stream << leftxp->eval_double();
				return stream.str() >= rightxp->eval_string();
			}
			//----------------------------------------------------------------------
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_double() >= rightxp->eval_double();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == INT)
			{
				return leftxp->eval_int() >= rightxp->eval_int();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_int() >= rightxp->eval_double();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == INT)
			{
				return leftxp->eval_double() >= rightxp->eval_int();
			}
		}
		else if(o_type == NOT_EQUAL)
		{
			
			std::stringstream stream;
			if(leftxp->get_type() == STRING && rightxp->get_type() == STRING)
			{
				return leftxp->eval_string() != rightxp->eval_string();
			}
			if(leftxp->get_type() == STRING && rightxp->get_type() == INT)
			{
				stream << rightxp->eval_int();
				return leftxp->eval_string() != stream.str();
			}
			if(leftxp->get_type() == STRING && rightxp->get_type() == DOUBLE)
			{
				stream << rightxp->eval_double();

				return leftxp->eval_string() != stream.str();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == STRING)
			{
				stream << leftxp->eval_int();
				return stream.str() != rightxp->eval_string();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == STRING)
			{
				stream << leftxp->eval_double();
				return stream.str() != rightxp->eval_string();
			}
			//----------------------------------------------------------------------
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_double() != rightxp->eval_double();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == INT)
			{
				return leftxp->eval_int() != rightxp->eval_int();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_int() != rightxp->eval_double();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == INT)
			{
				return leftxp->eval_double() != rightxp->eval_int();
			}
		}
		else if(o_type == PLUS)
		{
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_double() + rightxp->eval_double();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == INT)
			{
				return leftxp->eval_int() + rightxp->eval_int();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_int() + rightxp->eval_double();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == INT)
			{
				return leftxp->eval_double() + rightxp->eval_int();
			}
		}
		else if(o_type == MINUS)
		{
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_double() - rightxp->eval_double();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == INT)
			{
				return leftxp->eval_int() - rightxp->eval_int();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_int() - rightxp->eval_double();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == INT)
			{
				return leftxp->eval_double() - rightxp->eval_int();
			}
		}
	
		else if(o_type == OR)
		{
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_double() || rightxp->eval_double();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == INT)
			{
				return leftxp->eval_int() || rightxp->eval_int();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_int() || rightxp->eval_double();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == INT)
			{
				return leftxp->eval_double() || rightxp->eval_int();
			}
		}
		else if(o_type == AND)
		{
			//----------------------------------------------------------------
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_double() && rightxp->eval_double();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == INT)
			{
				return leftxp->eval_int() && rightxp->eval_int();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_int() && rightxp->eval_double();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == INT)
			{
				return leftxp->eval_double() && rightxp->eval_int();
			}
		}
		else if(o_type == MOD)
		{	
			//can only mod ints
			if(leftxp->get_type() == INT && rightxp->get_type() == INT)
			{
				return leftxp->eval_int() % rightxp->eval_int();
			}
		
		}
		else if(o_type == FLOOR)
		{

			if(rightxp->get_type() == INT)
				return (int)floor(rightxp->eval_int());
			else if (rightxp->get_type() == DOUBLE)
				return (int)floor(rightxp->eval_double());
			else return 0;		
		}
		else if(o_type == ABS)
		{

			if(rightxp->get_type() == INT)
				return abs(rightxp->eval_int());
			else if (rightxp->get_type() == DOUBLE)
				return abs(rightxp->eval_double());
			else return 0.0;		
		}
		else if(o_type == RANDOM)
		{

			if(rightxp->get_type() == INT)
				return rand() % rightxp->eval_int();
			else if (rightxp->get_type() == DOUBLE)
			{
				int tim = floor(rightxp->eval_double());
				return rand() % tim;
			}
			else return 0.0;		
		}
		else if(o_type == UNARY_MINUS)
		{
		//can only mod ints
			if(rightxp->get_type() == INT)
			{
				return rightxp->eval_int() * -1;
			}
			else if(rightxp->get_type() == DOUBLE)
			{
				return rightxp->eval_double() * -1;
			}
		
		}
		else if(o_type == NOT)
		{
		//can only mod ints
			if(rightxp->get_type() == INT)
			{
				return !rightxp->eval_int();
			}
			else if(rightxp->get_type() == DOUBLE)
			{
				return !rightxp->eval_double();
			}
		
		}
		else if(o_type == EQUAL)
		{


			std::stringstream stream;
			if(leftxp->get_type() == STRING && rightxp->get_type() == STRING)
			{
				return leftxp->eval_string() == rightxp->eval_string();
			}
			if(leftxp->get_type() == STRING && rightxp->get_type() == INT)
			{

				stream << rightxp->eval_int();
				return leftxp->eval_string() == stream.str();
			}
			if(leftxp->get_type() == STRING && rightxp->get_type() == DOUBLE)
			{
				stream << rightxp->eval_double();

				return leftxp->eval_string() == stream.str();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == STRING)
			{
				stream << leftxp->eval_int();
				return stream.str() == rightxp->eval_string();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == STRING)
			{
				stream << leftxp->eval_double();
				return stream.str() == rightxp->eval_string();
			}
			//--------------------------------------------------------------
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_double() == rightxp->eval_double();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == INT)
			{
				return leftxp->eval_int() == rightxp->eval_int();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_int() == rightxp->eval_double();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == INT)
			{
				return leftxp->eval_double() == rightxp->eval_int();
			}
			return 99;
		
		}

		else
		{	
			return 001;
		}
	}
	return 02;
}
double Expression::eval_double()
{
	if(m_kind == CONSTANT && m_type == DOUBLE)
	{
		return dbl_value;
	}
	else if(m_kind == VARIABLE)
	{
		return m_variable->get_double_value();
	}
	else if(m_kind == EXPRESSION){
			
		if(o_type == PLUS)
		{
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_double() + rightxp->eval_double();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == INT)
			{
				return leftxp->eval_int() + rightxp->eval_int();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_int() + rightxp->eval_double();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == INT)
			{
				return leftxp->eval_double() + rightxp->eval_int();
			}
		}
		else if(o_type == MINUS)
		{
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_double() - rightxp->eval_double();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == INT)
			{
				return leftxp->eval_int() - rightxp->eval_int();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_int() - rightxp->eval_double();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == INT)
			{
				return leftxp->eval_double() - rightxp->eval_int();
			}
		}
		else if(o_type == MULTIPLY)
		{	
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_double() * rightxp->eval_double();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == INT)
			{
				return leftxp->eval_int() * rightxp->eval_int();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_int() * rightxp->eval_double();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == INT)
			{
				return leftxp->eval_double() * rightxp->eval_int();
			}
			return 0.0;
		}
		else if(o_type == DIVIDE)
		{	
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_double() / rightxp->eval_double();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == INT)
			{
				return leftxp->eval_int() / rightxp->eval_int();
			}
			if(leftxp->get_type() == INT && rightxp->get_type() == DOUBLE)
			{
				return leftxp->eval_int() / rightxp->eval_double();
			}
			if(leftxp->get_type() == DOUBLE && rightxp->get_type() == INT)
			{
				return leftxp->eval_double() / rightxp->eval_int();
			}
			return 0.0;
		}
		else if(o_type == UNARY_MINUS)
		{
		//can only mod ints
			if(rightxp->get_type() == INT)
			{
				return rightxp->eval_int() * -1;
			}
			else if(rightxp->get_type() == DOUBLE)
			{
				return rightxp->eval_double() * -1;
			}
		
		}
		else if(o_type == COS)
		{


			if(rightxp->get_type() == INT)
				return cos(rightxp->eval_int()*M_PI/180);
			else if (rightxp->get_type() == DOUBLE)
				return cos(rightxp->eval_double()*M_PI/180);
			else return 0.0;		
		}
		else if(o_type == SIN)
		{

			if(rightxp->get_type() == INT)
				return sin(rightxp->eval_int()*M_PI/180);
			else if (rightxp->get_type() == DOUBLE)
				return sin(rightxp->eval_double()*M_PI/180);
			else return 0.0;		
		}
		else if(o_type == TAN)
		{

			if(rightxp->get_type() == INT)
				return tan(rightxp->eval_int()*M_PI/180);
			else if (rightxp->get_type() == DOUBLE)
				return tan(rightxp->eval_double()*M_PI/180);
			else return 0.0;		
		}
		else if(o_type == ACOS)
		{

			if(rightxp->get_type() == INT)
				return acos(rightxp->eval_int())*(180/M_PI);
			else if (rightxp->get_type() == DOUBLE)
				return acos(rightxp->eval_double())*(180/M_PI);
			else return 0.0;		
		}
		else if(o_type == ASIN)
		{

			if(rightxp->get_type() == INT)
				return asin(rightxp->eval_int())*(180/M_PI);
			else if (rightxp->get_type() == DOUBLE)
				return asin(rightxp->eval_double())*(180/M_PI);
			else return 0.0;		
		}
		else if(o_type == ATAN)
		{
			if(rightxp->get_type() == INT)
				return atan(rightxp->eval_int())*(180/M_PI);
			else if (rightxp->get_type() == DOUBLE)
				return atan(rightxp->eval_double())*(180/M_PI);
			else return 0.0;		
		}
		else if(o_type == SQRT)
		{
			if(rightxp->get_type() == INT)
				return sqrt(rightxp->eval_int());
			else if (rightxp->get_type() == DOUBLE)
				return sqrt(rightxp->eval_double());
			else return 0.0;		
		}
		else if(o_type == ABS)
		{

			if(rightxp->get_type() == INT)
				return abs(rightxp->eval_int());
			else if (rightxp->get_type() == DOUBLE)
				return abs(rightxp->eval_double());
			else return 0.0;

		}
		
		else return 0.0;
	}
	else return 0.0;
			return 0.0;
}
string Expression::eval_string()
{
	std::stringstream stream;
	if(m_kind == CONSTANT && m_type == STRING)
	{
		return str_value;
	}
	else if(m_kind == VARIABLE)
	{
		return m_variable->get_string_value();
	}
	else if(m_kind == EXPRESSION){
		
		if(o_type == PLUS)
		{
	
			if(leftxp->get_type() == STRING)
			{
				stream << leftxp->eval_string();
			}		
			else if(leftxp->get_type() == INT)
			{
				stream << leftxp->eval_int();
			}
			else if(leftxp->get_type() == DOUBLE)
			{
				stream << leftxp->eval_double();
			}
			if(rightxp->get_type() == STRING)
			{
				stream << rightxp->eval_string();
			}	
			else if(rightxp->get_type() == INT)
			{
				stream << rightxp->eval_int();
			}
			else if(rightxp->get_type() == DOUBLE)
			{
				stream << rightxp->eval_double();
			}
			return stream.str();
		}
	else return "";
	}
	else return "";
}
Gpl_type Expression::get_type()
{
	return m_type;
}
