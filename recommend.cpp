#include<bits/stdc++.h>
using namespace std;

// Movie structure
struct Movie {
    std::string title;
    std::vector<std::string> genres;
};

// User structure
struct User {
    std::string username;
    std::map<std::string, int> genrePreferences;
};

// Function to calculate the similarity between a movie and a user's preferences
double calculateMovieUserSimilarity(const Movie& movie, const User& user) {
    double similarity = 0.0;

    for (const std::string& genre : movie.genres) {
        if (user.genrePreferences.count(genre) > 0) {
            similarity += user.genrePreferences.at(genre);
        }
    }

    return similarity;
}

// Function to recommend movies to a user
std::vector<Movie> recommendMovies(const std::vector<Movie>& movies, const User& user, int numRecommendations) {
    std::vector<std::pair<Movie, double>> movieSimilarities;

    for (const Movie& movie : movies) {
        double similarity = calculateMovieUserSimilarity(movie, user);
        movieSimilarities.emplace_back(movie, similarity);
    }

    // Sort movies by similarity in descending order
    std::sort(movieSimilarities.begin(), movieSimilarities.end(),
              [](const std::pair<Movie, double>& a, const std::pair<Movie, double>& b) {
                  return a.second > b.second;
              });

    // Get the top N recommendations
    std::vector<Movie> recommendations;
    for (int i = 0; i < numRecommendations && i < movieSimilarities.size(); ++i) {
        recommendations.push_back(movieSimilarities[i].first);
    }

    return recommendations;
}

int main() {
    // Sample movie data
    std::vector<Movie> movies = {
        {"Movie1", {"Action", "Adventure"}},
        {"Movie2", {"Drama", "Romance"}},
        {"Movie3", {"Comedy"}},
        {"Movie4", {"Action", "Comedy"}},
        // Add more movies here
    };

    // Sample user preferences
    User user;
    user.username = "User1";
    user.genrePreferences = {
        {"Action", 5},
        {"Drama", 3},
        {"Comedy", 4},
        // Add more genre preferences here
    };

    int numRecommendations = 3;

    // Get movie recommendations for the user
    std::vector<Movie> recommendations = recommendMovies(movies, user, numRecommendations);

    // Display recommended movies
    std::cout << "Recommended movies for " << user.username << ":" << std::endl;
    for (const Movie& movie : recommendations) {
        std::cout << movie.title << std::endl;
    }

    return 0;
}
