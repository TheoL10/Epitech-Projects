import 'dart:html';

import 'package:flutter/material.dart';
import '/components/my_button.dart';
import '/components/my_textfield.dart';
import '/components/square_tile.dart';
import 'dart:convert';
import 'dart:core';
import 'package:http/http.dart' as http;
import 'login_page.dart';

class SettingsPage extends StatelessWidget {
  SettingsPage({super.key});

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
                Icons.settings,
                size: 100,
              ),

              SizedBox(
              height: MediaQuery.of(context).size.height / 51.2,
            ),

              // welcome back, you've been missed!
              Text(
                'Connect your accounts',
                style: TextStyle(
                  color: Colors.grey[700],
                  fontSize: 16,
                ),
              ),

              SizedBox(
              height: MediaQuery.of(context).size.height / 102.4,
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
                        'Chose from',
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
                children: [
                  // google button
                  IconButton(
                      icon: Icon(Icons.discord),
                      onPressed: () async {
                        ApiService.authDiscord();
                      },
                    ),

                  SizedBox(width: 20),

                  // apple button
                  SquareTile(imagePath: 'lib/images/google.png')
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
                    'All set up?',
                    style: TextStyle(color: Colors.grey[700]),
                  ),
                  const SizedBox(width: 4),
                  // register now button
                  TextButton(
                    onPressed: () {
                      Navigator.pushNamed(context, '/home', arguments: {});
                    },
                    child: const Text(
                      'Back to services',
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