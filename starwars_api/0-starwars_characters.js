#!/usr/bin/node

const request = require('request');

// Get the Movie ID from the first command-line argument
const movieId = process.argv[2];

// API endpoint for the specific movie
const apiUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

// Function to make a request and return a promise
const makeRequest = (url) => {
  return new Promise((resolve, reject) => {
    request(url, (error, response, body) => {
      if (error) {
        reject(error);
      } else {
        resolve(body);
      }
    });
  });
};

// Main function to get characters
const getCharacters = async () => {
  try {
    const movieResponse = await makeRequest(apiUrl);
    const movie = JSON.parse(movieResponse);
    const characters = movie.characters;

    for (const url of characters) {
      const characterResponse = await makeRequest(url);
      const character = JSON.parse(characterResponse);
      console.log(character.name);
    }
  } catch (error) {
    console.error('Error:', error);
  }
};

// Call the main function
getCharacters();
