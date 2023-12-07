#!/usr/bin/node

const fetch = require('node-fetch');

const getStarWarsCharacters = async (movieId) => {
  try {
    // Base URL for the Star Wars API
    const baseUrl = 'https://swapi.dev/api';

    // Fetch film data
    const filmResponse = await fetch(`${baseUrl}/films/${movieId}/`);

    if (!filmResponse.ok) {
      throw new Error('Error fetching film data');
    }

    const filmData = await filmResponse.json();

    // Fetch and print each character's name
    for (const characterUrl of filmData.characters) {
      const characterResponse = await fetch(characterUrl);

      if (!characterResponse.ok) {
        console.error('Error fetching character data');
        continue;
      }

      const characterData = await characterResponse.json();
      console.log(characterData.name);
    }
  } catch (error) {
    console.error(error.message);
  }
};

// Get movie ID from command line argument
const movieId = process.argv[2];

if (movieId) {
  getStarWarsCharacters(movieId);
} else {
  console.log('Please provide a movie ID as a command line argument.');
}
