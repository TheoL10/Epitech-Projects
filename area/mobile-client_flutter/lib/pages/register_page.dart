import 'dart:html';

import 'package:flutter/material.dart';
import '/components/my_button.dart';
import '/components/my_textfield.dart';
import '/components/square_tile.dart';
import 'dart:convert';
import 'dart:core';
import 'package:http/http.dart' as http;
import 'login_page.dart';

class RegisterPage extends StatelessWidget {
  RegisterPage({super.key});

  // text editing controllers
  final usernameController = TextEditingController();
  final passwordController = TextEditingController();
  final phoneController = TextEditingController();
  final emailController = TextEditingController();
  final confirmPasswordController = TextEditingController();

  // sign user in method


  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey[300],
      body: SafeArea(
        child: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              SizedBox(
              height: MediaQuery.of(context).size.height / 51.2,
            ),

              // logo
              const Icon(
                Icons.account_circle,
                size: 100,
              ),

              SizedBox(
              height: MediaQuery.of(context).size.height / 51.2,
            ),

              // welcome back, you've been missed!
              Text(
                'Create an account',
                style: TextStyle(
                  color: Colors.grey[700],
                  fontSize: 16,
                ),
              ),

              SizedBox(
              height: MediaQuery.of(context).size.height / 102.4,
            ),

              MyTextField(controller: emailController, hintText: 'Email', obscureText: false),

              SizedBox(
              height: MediaQuery.of(context).size.height / 256,
            ),

              MyTextField(controller: phoneController, hintText: 'Phone', obscureText: false),

              SizedBox(
              height: MediaQuery.of(context).size.height / 256,
            ),
              
              // username textfield
              MyTextField(
                controller: usernameController,
                hintText: 'Name',
                obscureText: false,
              ),

              SizedBox(
              height: MediaQuery.of(context).size.height / 256,
            ),

              // password textfield
              MyTextField(
                controller: passwordController,
                hintText: 'Password',
                obscureText: true,
              ),

              SizedBox(
              height: MediaQuery.of(context).size.height / 256,
            ),

              MyTextField(controller: confirmPasswordController, hintText: 'Confirm Password', obscureText: true),



              SizedBox(
              height: MediaQuery.of(context).size.height / 256,
            ),

              // forgot password

              SizedBox(
              height: MediaQuery.of(context).size.height / 102.4,
            ),

              // sign in button
              MyButton(
                onTap: () async {
                  print("login");
                  print(usernameController.text);
                  print(passwordController.text);
                  if (passwordController.text != confirmPasswordController.text) {
                    //diesplay a message on screen
                    //return a message that dissapears after a while with a popup and a timer and the text is red 'passwords do not match'
                    print("why?");
                    return SnackBar(
                      content: Text('Passwords do not match'),
                      duration: Duration(seconds: 3),
                    );

                  }
                  else {
                      Navigator.pushNamed(context, '/login');
                      Map<String, dynamic> response = await ApiService.register(usernameController.text, emailController.text, phoneController.text, passwordController.text);
                      print(response);
                      print("T  ARTIN");
                      if(response["msg"] == "User created") {
                        Navigator.pushNamed(context, '/login');
                      } else if (response["msg"] == "User already exists") {
                        print("why?iiiiiiiiiii");
                        return SnackBar(
                          content: Text('User already exists'),
                          duration: Duration(seconds: 3),
                        );
                      }
                  }
                },
              ),

              SizedBox(
              height: MediaQuery.of(context).size.height / 51.2,
            ),

              // or continue with
              Padding(
                padding: const EdgeInsets.symmetric(horizontal: 25.0),
                child: Row(
                  children: [
                    Expanded(
                      child: Divider(
                        thickness: 0.5,
                        color: Colors.grey[400],
                      ),
                    ),
                    Padding(
                      padding: const EdgeInsets.symmetric(horizontal: 10.0),
                      child: Text(
                        'Or continue with',
                        style: TextStyle(color: Colors.grey[700]),
                      ),
                    ),
                    Expanded(
                      child: Divider(
                        thickness: 0.5,
                        color: Colors.grey[400],
                      ),
                    ),
                  ],
                ),
              ),

              SizedBox(
              height: MediaQuery.of(context).size.height / 51.2,
            ),

              // google + apple sign in buttons
              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: const [
                  // google button
                  SquareTile(imagePath: 'lib/images/google.png'),

                  SizedBox(width: 20),

                  // apple button
                  SquareTile(imagePath: 'lib/images/apple.png')
                ],
              ),

              SizedBox(
              height: MediaQuery.of(context).size.height / 51.2,
            ),

              // not a member? register now
              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Text(
                    'Already a member?',
                    style: TextStyle(color: Colors.grey[700]),
                  ),
                  const SizedBox(width: 4),
                  // register now button
                  TextButton(
                    onPressed: () {
                      Navigator.pushNamed(context, '/login');
                    },
                    child: const Text(
                      'Login now',
                      style: TextStyle(
                        color: Colors.blue,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                  ),
                ],
              )
            ],
          ),
        ),
      ),
    );
  }
}