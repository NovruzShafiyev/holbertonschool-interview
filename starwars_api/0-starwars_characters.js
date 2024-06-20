#!/usr/bin/node

const request = require('request');

// Get the Movie ID from the first command-line argument
const movieId = process.argv[2];

// API endpoint for the specific movie
const apiUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

// Make a request to the API endpoint
request(apiUrl, function (error, response, body) {
  if (error) {
    console.error('Error:', error);
    return;
  }

  // Parse the response body as JSON
  const movie = JSON.parse(body);

  // Get the list of character URLs
  const characters = movie.characters;

  // Function to fetch and print a character name
  const fetchCharacterName = (url) => {
    request(url, function (error, response, body) {
      if (!error && response.statusCode === 200) {
        const character = JSON.parse(body);
        console.log(character.name);
      }
    });
  };

  // Fetch and print each character name in the same order
  characters.forEach(fetchCharacterName);
});
