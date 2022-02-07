
import React, { useEffect } from 'react';
import { SafeAreaView, ScrollView, StatusBar, StyleSheet, Text, useColorScheme, View, NativeModules } from 'react-native';

const { Ijsi } = NativeModules;

const App = () => {
	const isDarkMode = useColorScheme() === 'dark';

	useEffect(() => {
		Ijsi.init();
		setTimeout(() => {
			console.log(global.greet());
		}, 2000);
	},[])

	return (
		<SafeAreaView style={{ flex: 1 }}>
			<StatusBar barStyle={isDarkMode ? 'light-content' : 'dark-content'} />
			<ScrollView
				contentInsetAdjustmentBehavior="automatic"
				style={{ flex: 1 }}>
				<Text style={[styles.sectionTitle, { alignSelf: 'center', marginTop: '20%' }]}>Hello IJSI</Text>
			</ScrollView>
		</SafeAreaView>
	);
};

const styles = StyleSheet.create({
	sectionContainer: {
		marginTop: 32,
		paddingHorizontal: 24,
	},
	sectionTitle: {
		fontSize: 24,
		fontWeight: '600',
	},
	sectionDescription: {
		marginTop: 8,
		fontSize: 18,
		fontWeight: '400',
	},
	highlight: {
		fontWeight: '700',
	},
});

export default App;
